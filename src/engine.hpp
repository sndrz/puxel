#ifndef __ENGINE__
#define __ENGINE__


#include "videom.hpp"
#include "scenem.hpp"

namespace engine {

class Engine {
public:

    video::Manager* videoManager;
    scene::Manager* sceneManager;

    Engine() {};
    ~Engine() {};

private:

};

}

#endif // __ENGINE__
