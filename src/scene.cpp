/*
    Puxel

    See LICENSE for copyright notes.
    Sergey Ivanov <sivanov@openmailbox.org>
*/

#include "scene.hpp"

using namespace puxel;

void Scene::Draw() {

    DrawCanvas();
    DrawEffects();
    DrawUIDetails();
    DrawUIElements();
    DrawUIPopup();

} // function Scene::Draw
