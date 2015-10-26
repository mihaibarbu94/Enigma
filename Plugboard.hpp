#ifndef PLUGBOARD_HPP
#define PLUGBOARD_HPP

#include <cstring>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <stdlib.h>

#include "Components.hpp"

class Plugboard : public Components{
    public:
        Plugboard(const char *fileName);
        int encode(int input);
    private:
        int plugboardConfig[26];//Encode::ALPHABET_SIZE
        bool boolPlugboardConfig[26];
};

#endif // PLUGBOARD_HPP
