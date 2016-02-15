#ifndef __VIDEOM__
#define __VIDEOM__

#include "SDL/SDL.h"

namespace video {

class Manager {
public:

    Manager() {};
    ~Manager() {};

private:

    SDL_Surface* screenSurface;
    int screenX, screenY;

};

}

#endif // __VIDEOM__
