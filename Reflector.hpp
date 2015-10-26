#ifndef REFLECTOR_HPP
#define REFLECTOR_HPP

#include "Components.hpp"
#include <fstream>
//#include "Encode.hpp"

class Encode; // let the compiler know such a class will be defined

class Reflector : public Components{
    public:
        int encode(int input);
};

#endif // REFLECTOR_HPP
