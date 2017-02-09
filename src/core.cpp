/*
    Puxel

    See LICENSE for copyright notes.
    Sergey Ivanov <sivanov@openmailbox.org>
*/

#include "core.hpp"

using namespace puxel;

Core :: Core() {

    puVideo = new Video();

} // function Core :: Core

Core :: ~Core() {

    delete puVideo;
    SDL_Quit();

} // function Core :: ~Core
