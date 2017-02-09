/*
    Puxel

    See LICENSE for copyright notes.
    Sergey Ivanov <sivanov@openmailbox.org>
*/

#ifndef __CORE_HPP
#define __CORE_HPP

#include "SDL/SDL.h"

#include "video.hpp"
#include "scene.hpp"
#include "resource.hpp"
#include "statem.hpp"

namespace puxel {

    class Core {
    private:

        Video* puVideo;

    public:

        Core();
        ~Core();

    }; // class Core

} // namespace puxel

#endif // __CORE_HPP
