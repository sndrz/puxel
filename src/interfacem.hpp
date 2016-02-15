#ifndef __INTERFACEM__
#define __INTERFACEM__

#include <vector>
#include "interface.hpp"

namespace interface {

class Manager {
public:

    Manager() {};
    ~Manager() {};

private:

    std::vector<Base*> items;

};

}

#endif // __INTERFACEM__
