/*
    Puxel

    See LICENSE for copyright notes.
    Sergey Ivanov <sivanov@openmailbox.org>
*/

#ifndef __VIDEO_HPP
#define __VIDEO_HPP

#include "SDL/SDL.h"

namespace puxel {

    class Video {
    private:

        SDL_Surface* screen;

    public:

        Video();
        ~Video();

    }; // class Video

} // namespace puxel

#endif // __VIDEO_HPP
