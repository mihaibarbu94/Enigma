#ifndef ROTOR_HPP
#define ROTOR_HPP

#include <cstring>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include "Components.hpp"


class Rotor : public Components{
    public:
        Rotor(const char *fileName);
        int encode(int input);
        int encodeBackwords(int input);
        bool hasFullyRotated();
        void rotate();
    private:
        int rotorConfig[26];
        int numOfRotations;

};

#endif // ROTOR_HPP
