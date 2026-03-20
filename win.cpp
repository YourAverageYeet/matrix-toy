#include "win.h"
#include "fl/window.h"

void cb_mat_apply(Fl_Return_Button*, Matrix33* mat){
    mat->setMatValue(0, 0, mat_x_1->value());
    mat->setMatValue(0, 1, mat_x_2->value());
    mat->setMatValue(0, 2, mat_x_3->value());
    mat->setMatValue(1, 0, mat_y_1->value());
    mat->setMatValue(1, 1, mat_y_2->value());
    mat->setMatValue(1, 2, mat_y_3->value());
    mat->setMatValue(2, 0, mat_z_1->value());
    mat->setMatValue(2, 1, mat_z_2->value());
    mat->setMatValue(2, 2, mat_z_3->value());
}

void cb_mat_view_reset(Fl_Button*, bool* r){
    mat_x_1->value(1.0);
    mat_x_2->value(0.0);
    mat_x_3->value(0.0);
    mat_y_1->value(0.0);
    mat_y_2->value(1.0);
    mat_y_3->value(0.0);
    mat_z_1->value(0.0);
    mat_z_2->value(0.0);
    mat_z_3->value(1.0);
    *r = true;
}

void cb_keyed_mode(Fl_Light_Button*, void*){
    if(mat_x_1->active()){
        mat_x_1->deactivate();
    } else {
        mat_x_1->activate();
    }
    if(mat_x_2->active()){
        mat_x_2->deactivate();
    } else {
        mat_x_2->activate();
    }
    if(mat_x_3->active()){
        mat_x_3->deactivate();
    } else {
        mat_x_3->activate();
    }
    if(mat_y_1->active()){
        mat_y_1->deactivate();
    } else {
        mat_y_1->activate();
    }
    if(mat_y_2->active()){
        mat_y_2->deactivate();
    } else {
        mat_y_2->activate();
    }
    if(mat_y_3->active()){
        mat_y_3->deactivate();
    } else {
        mat_y_3->activate();
    }
    if(mat_z_1->active()){
        mat_z_1->deactivate();
    } else {
        mat_z_1->activate();
    }
    if(mat_z_2->active()){
        mat_z_2->deactivate();
    } else {
        mat_z_2->activate();
    }
    if(mat_z_3->active()){
        mat_z_3->deactivate();
    } else {
        mat_z_3->activate();
    }
    if(mat_apply_button->active()){
        mat_apply_button->deactivate();
    } else {
        mat_apply_button->activate();
    }
}
