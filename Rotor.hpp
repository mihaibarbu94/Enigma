#ifndef ROTOR_HPP
#define ROTOR_HPP

#include <cstring>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include "Components.hpp"
#include "Utils.hpp"

using namespace std;

class Rotor : public Components{
    public:
        Rotor(const char *fileName);
        int encode(int input);
        int encodeBackwords(int input);
        bool hasFullyRotated();
        void rotate();
    private:
        int *rotorConfig;
        int numOfRotations;

};

#endif // ROTOR_HPP
