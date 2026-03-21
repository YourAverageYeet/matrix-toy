#include <FL/Fl.H>
#include <cmath>

#include "fl/window.h"
#include "mat.h"
#include "sdl.h"

ShapePoint operator*(const Matrix33& mat, const ShapePoint& p){
    ShapePoint out;
    double iX = mat.getMatValue(0, 0) * p.first;
    iX += mat.getMatValue(0, 1) * p.second;
    iX += mat.getMatValue(0, 2);
    double iY = mat.getMatValue(1, 0) * p.first;
    iY += mat.getMatValue(1, 1) * p.second;
    iY += mat.getMatValue(1, 2);
    double norm = mat.getMatValue(2, 0) * p.first;
    norm += mat.getMatValue(2, 1) * p.second;
    norm += mat.getMatValue(2, 2);
    out.first = iX / norm;
    out.second = iY / norm;
    return out;
}

void drawShape(const SDLVisualizer& v, const Shape& s, const Matrix33& tM,
    const Matrix33& wM){
        Matrix33 M = wM * tM;
        ScreenShape toScreen = {};
        for(size_t i = 0; i < s.size(); i++){
            ShapePoint tmp = M * s[i];
            ScreenPoint sp = {(int)tmp.first, (int)tmp.second};
            toScreen.push_back(sp);
        }
        v.clearCanvas();
        v.drawScreenShape(toScreen);
}

void makeRotation(Matrix33& rM, double ang){
    rM = ident33;
    rM.setMatValue(0, 0, std::cos(ang));
    rM.setMatValue(1, 1, std::cos(ang));
    rM.setMatValue(0, 1, -std::sin(ang));
    rM.setMatValue(1, 0, std::sin(ang));
}

int main(void){
    Matrix33 baseMat = ident33;
    double theta = 0.0;
    Matrix33 rotMat;
    makeRotation(rotMat, theta);
    Matrix33 worldMat(0.0);
    worldMat.setMatValue(0, 0, 16);
    worldMat.setMatValue(1, 1, -16);
    worldMat.setMatValue(2, 2, 1);
    worldMat.setMatValue(0, 2, 320);
    worldMat.setMatValue(1, 2, 240);
    Shape baseShape = {
        {-1.0, -(2.0/3.0)},
        { 1.0, -(2.0/3.0)},
        { 0.0, (4.0/3.0)}
    };
    bool exit = false;
    bool reset = false;
    SDLVisualizer vis;
    Fl_Double_Window* win = make_main_win(&baseMat, &reset);
    mat_x_1->value(1.0);
    mat_y_2->value(1.0);
    mat_z_3->value(1.0);
    win->show();
    drawShape(vis, baseShape, (baseMat * rotMat), worldMat);
    while(!exit && Fl::check()){
        char useKeys = mat_keyed_mode->value();
        if(reset){
            baseMat = ident33;
            theta = 0.0;
            makeRotation(rotMat, theta);
            reset = false;
        }
        vis.processEvents(
            baseMat,
            theta,
            exit,
            useKeys
        );
        makeRotation(rotMat, theta);
        Matrix33 multMat = baseMat * rotMat;
        if(useKeys){
            mat_x_1->value(multMat.getMatValue(0, 0));
            mat_x_2->value(multMat.getMatValue(0, 1));
            mat_x_3->value(multMat.getMatValue(0, 2));
            mat_y_1->value(multMat.getMatValue(1, 0));
            mat_y_2->value(multMat.getMatValue(1, 1));
            mat_y_3->value(multMat.getMatValue(1, 2));
            mat_z_1->value(multMat.getMatValue(2, 0));
            mat_z_2->value(multMat.getMatValue(2, 1));
            mat_z_3->value(multMat.getMatValue(2, 2));
        }
        drawShape(vis, baseShape, multMat, worldMat);
        vis.redraw();
        SDL_Delay(16);
    }
    if(win->visible()){
        win->hide();
    }
    return 0;
}
