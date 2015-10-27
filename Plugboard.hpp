#ifndef PLUGBOARD_HPP
#define PLUGBOARD_HPP

#include <cstring>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <stdlib.h>

#include "Components.hpp"
#include "Utils.hpp"

class Plugboard : public Components{
    public:
        Plugboard(const char *fileName);
        int encode(int input);
    private:
        int plugboardConfig[ALPHABET_SIZE];
        bool boolPlugboardConfig[ALPHABET_SIZE];
};

#endif // PLUGBOARD_HPP
