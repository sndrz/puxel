/*
    Puxel

    See LICENSE for copyright notes.
    Sergey Ivanov <sivanov@openmailbox.org>
*/

#include "video.hpp"

using namespace puxel;

Video :: Video() {

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
//        printf("%s\n", SDL_GetError());
    }; // if

    screen = SDL_SetVideoMode(800, 600, 16, SDL_HWSURFACE|SDL_DOUBLEBUF);
    if (!screen) {
//        printf("%s\n", SDL_GetError());
    }; // if

} // function Video :: Video

Video :: ~Video() {

} // function Video :: ~Video

