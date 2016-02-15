#ifndef __SCENEM__
#define __SCENEM__

#include <vector>
#include "scene.hpp"

namespace scene {

class Manager {
public:

    Manager() {};
    ~Manager() {};

    void Draw() {};

private:

    std::vector<Scene*> scenes;
    uint32_t currentScene;

    void DrawCanvas() {};
    void DrawEffects() {};
    void DrawHUD() {};
    void DrawUI() {};
    void DrawPopup() {};

};

}

#endif // __SCENEM__
