/*
    Puxel

    See LICENSE for copyright notes.
    Sergey Ivanov <sivanov@openmailbox.org>
*/

#ifndef __SCENE_HPP
#define __SCENE_HPP

namespace puxel {

    class Scene {
    private:

        void DrawCanvas() {};
        void DrawEffects() {};
        void DrawUIDetails() {};
        void DrawUIElements() {};
        void DrawUIPopup() {};

    public:

        void Draw();

    }; // class Scene

} // namespace puxel

#endif // __SCENE_HPP
