#ifndef REFLECTOR_HPP
#define REFLECTOR_HPP

#include "Components.hpp"
#include <fstream>
//#include "Encode.hpp"

class Encode; // let the compiler know such a class will be defined

class Reflector : public Components{
    public:
        Reflector();
        virtual int encode(int input);
        int reflectorConfig[26];//Encode::ALPHABET_SIZE
    protected:
    private:

};

#endif // REFLECTOR_HPP
