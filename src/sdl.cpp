#include "sdl.h"
#include "mat.h"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>

SDLVisualizer::SDLVisualizer(){
    int rFlags = SDL_RENDERER_SOFTWARE;
    int wFlags = SDL_WINDOW_SHOWN;
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::stringstream ss("");
        ss << "Failure in SDL_Init(): " << SDL_GetError();
        throw std::runtime_error(ss.str());
    }
    wind = SDL_CreateWindow(
        "Transformed Triangle View",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        SCR_W,
        SCR_H,
        wFlags
    );
    if(!wind){
        std::stringstream ss("");
        ss << "Failure in SDL_CreateWindow(): " << SDL_GetError();
        throw std::runtime_error(ss.str());
    }
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "nearest");
    rend = SDL_CreateRenderer(
        wind,
        -1,
        rFlags
    );
    if(!rend){
        SDL_DestroyWindow(wind);
        std::stringstream ss("");
        ss << "Failure in SDL_CreateRenderer(): " << SDL_GetError();
        throw std::runtime_error(ss.str());
    }
}

SDLVisualizer::~SDLVisualizer(){
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(wind);
}

void SDLVisualizer::redraw() const {
    SDL_RenderPresent(rend);
}

void SDLVisualizer::drawScreenShape(std::vector<ScreenPoint>& points) const {
    SDL_SetRenderDrawColor(
        rend,
        DRAW_R,
        DRAW_G,
        DRAW_B,
        SDL_ALPHA_OPAQUE
    );
    for(size_t i = 0; i < (points.size() - 1); i++){
        SDL_Point ps = points[i];
        SDL_Point pe = points[i + 1];
        SDL_RenderDrawLine(
            rend,
            ps.x,
            ps.y,
            pe.x,
            pe.y
        );
    }
    SDL_RenderDrawLine(
        rend,
        points[points.size() - 1].x,
        points[points.size() - 1].y,
        points[0].x,
        points[0].y
    );
}

void SDLVisualizer::clearCanvas() const {
    SDL_SetRenderDrawColor(rend, BACK_R, BACK_G, BACK_B, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(rend);
}

void SDLVisualizer::processEvents(Matrix33& base, double& ang, bool& e) const {
    SDL_Event ev;
    SDL_PollEvent(&ev);
    if(ev.type == SDL_KEYDOWN){
        switch(ev.key.keysym.sym){
            case(SDLK_ESCAPE): {
                e = true;
                break;
            }
            case(SDLK_UP): {
                double tmp = base.getMatValue(1, 2);
                tmp++;
                base.setMatValue(1, 2, tmp);
                break;
            }
            case(SDLK_DOWN): {
                double tmp = base.getMatValue(1, 2);
                tmp--;
                base.setMatValue(1, 2, tmp);
                break;
            }
            case(SDLK_LEFT): {
                double tmp = base.getMatValue(0, 2);
                tmp--;
                base.setMatValue(0, 2, tmp);
                break;
            }
            case(SDLK_RIGHT): {
                double tmp = base.getMatValue(0, 2);
                tmp++;
                base.setMatValue(0, 2, tmp);
                break;
            }
            case(SDLK_TAB): {
                base = ident33;
                ang = 0;
                break;
            }
            case(SDLK_4):
            case(SDLK_KP_4): {
                double tmp = 0.0;
                if(ev.key.keysym.mod & KMOD_SHIFT){
                    tmp = base.getMatValue(1, 0);
                } else {
                    tmp = base.getMatValue(0, 1);
                }
                tmp--;
                if(ev.key.keysym.mod & KMOD_SHIFT){
                    base.setMatValue(1, 0, tmp);
                } else {
                    base.setMatValue(0, 1, tmp);
                }
                break;
            }
            case(SDLK_5):
            case(SDLK_KP_5): {
                double tmp = 0.0;
                if(ev.key.keysym.mod & KMOD_SHIFT){
                    tmp = base.getMatValue(1, 0);
                } else {
                    tmp = base.getMatValue(0, 1);
                }
                tmp++;
                if(ev.key.keysym.mod & KMOD_SHIFT){
                    base.setMatValue(1, 0, tmp);
                } else {
                    base.setMatValue(0, 1, tmp);
                }
                break;
            }
            case(SDLK_7):
            case(SDLK_KP_7): {
                double tmp = 0.0;
                if(ev.key.keysym.mod & KMOD_SHIFT){
                    tmp = base.getMatValue(1, 1);
                } else {
                    tmp = base.getMatValue(0, 0);
                }
                tmp--;
                if(ev.key.keysym.mod & KMOD_SHIFT){
                    base.setMatValue(1, 1, tmp);
                } else {
                    base.setMatValue(0, 0, tmp);
                }
                break;
            }
            case(SDLK_8):
            case(SDLK_KP_8): {
                double tmp = 0.0;
                if(ev.key.keysym.mod & KMOD_SHIFT){
                    tmp = base.getMatValue(1, 1);
                } else {
                    tmp = base.getMatValue(0, 0);
                }
                tmp++;
                if(ev.key.keysym.mod & KMOD_SHIFT){
                    base.setMatValue(1, 1, tmp);
                } else {
                    base.setMatValue(0, 0, tmp);
                }
                break;
            }
            case(SDLK_1):
            case(SDLK_KP_1): {
                if(ev.key.keysym.mod & KMOD_SHIFT){
                    ang += (3.1415926 / 180.0) * 10.0;
                } else {
                    ang += (3.1415926 / 180.0);
                }
                break;
            }
            case(SDLK_2):
            case(SDLK_KP_2): {
                if(ev.key.keysym.mod & KMOD_SHIFT){
                    ang -= (3.1415926 / 180.0) * 10.0;
                } else {
                    ang -= (3.1415926 / 180.0);
                }
                break;
            }
            case(SDLK_0):
            case(SDLK_KP_9): {
                double tmp = base.getMatValue(2, 2);
                tmp += 0.05;
                base.setMatValue(2, 2, tmp);
                break;
            }
            case(SDLK_9):
            case(SDLK_KP_6): {
                double tmp = base.getMatValue(2, 2);
                tmp -= 0.05;
                base.setMatValue(2, 2, tmp);
                break;
            }
            case(SDLK_EQUALS):
            case(SDLK_KP_MULTIPLY): {
                double tmp = 0.0;
                if(ev.key.keysym.mod & KMOD_SHIFT){
                    tmp = base.getMatValue(2, 1);
                } else {
                    tmp = base.getMatValue(2, 0);
                }
                tmp += 0.05;
                if(ev.key.keysym.mod & KMOD_SHIFT){
                    base.setMatValue(2, 1, tmp);
                } else {
                    base.setMatValue(2, 0, tmp);
                }
                break;
            }
            case(SDLK_MINUS):
            case(SDLK_KP_DIVIDE): {
                double tmp = 0.0;
                if(ev.key.keysym.mod & KMOD_SHIFT){
                    tmp = base.getMatValue(2, 1);
                } else {
                    tmp = base.getMatValue(2, 0);
                }
                tmp -= 0.05;
                if(ev.key.keysym.mod & KMOD_SHIFT){
                    base.setMatValue(2, 1, tmp);
                } else {
                    base.setMatValue(2, 0, tmp);
                }
                break;
            }
            default: {
                break;
            }
        }
    } else if(ev.type == SDL_QUIT){
        e = true;
    }
}
