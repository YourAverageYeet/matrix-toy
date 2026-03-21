#ifndef     SDL_H_INCLUDED
#define     SDL_H_INCLUDED

#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <time.h>
#include <utility>
#include <vector>
#include <stdexcept>
#include <sstream>

#include "mat.h"

#define     SCR_W   640     // Default SDL window width
#define     SCR_H   480     // Default SDL window height

#define     BACK_R  0x23    // Deafult red channel value for backgound
#define     BACK_G  0x26    // Deafult green channel value for backgound
#define     BACK_B  0x27    // Deafult blue channel value for backgound

#define     DRAW_R  0xff    // ++
#define     DRAW_G  0xff    //  +- SDL drawing color
#define     DRAW_B  0xff    // ++

using ShapePoint = std::pair<double, double>;
using ScreenPoint = SDL_Point;

using Shape = std::vector<ShapePoint>;
using ScreenShape = std::vector<ScreenPoint>;

class SDLVisualizer {
        SDL_Renderer*   rend;   // The renderer for this specific window
        SDL_Window*     wind;   // The actual window itself
    public:
        SDLVisualizer();
        ~SDLVisualizer();
        void redraw() const;
        void drawScreenShape(std::vector<ScreenPoint>& points) const;
        void clearCanvas() const;
        void processEvents(Matrix33& base, double& ang,
            bool& e, char keys) const;
};



#endif  //  SDL_H_INCLUDED
