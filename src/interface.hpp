#ifndef __INTERFACE__
#define __INTERFACE__

#include "tools.hpp"

namespace interface {

class Base {
public:

    Base() {};
    ~Base() {};

    void GenerateEvent(tools::click _point) {};

protected:

    uint32_t id;
    uint32_t x, y, width, height;

};

class Button : public Base {
public:

    Button() {};
    ~Button() {};

    void GenerateEvent(tools::click _point) {};

private:

};

}

#endif // __INTERFACE__
