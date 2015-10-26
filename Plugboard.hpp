#ifndef PLUGBOARD_HPP
#define PLUGBOARD_HPP

#include "Components.hpp"

class Plugboard : public Components{
    public:
        Plugboard(const char *fileName);
        virtual int encode(int input);
        int plugboardConfig[26];//Encode::ALPHABET_SIZE
        bool boolPlugboardConfig[26];
    protected:
    private:
};

#endif // PLUGBOARD_HPP
