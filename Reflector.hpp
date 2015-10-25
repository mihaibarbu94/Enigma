#ifndef REFLECTOR_HPP
#define REFLECTOR_HPP

#include "Components.hpp"
#include <fstream>

class Reflector : public Components{
    public:
        Reflector();
        virtual int encode(int input);
        int getNumOfRotations();
    protected:
    private:
};

#endif // REFLECTOR_HPP
