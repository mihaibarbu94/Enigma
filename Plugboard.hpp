#ifndef PLUGBOARD_HPP
#define PLUGBOARD_HPP

#include "Components.hpp"

class Plugboard : public Components{
    public:
        Plugboard(const char *fileName);
        virtual int encode(int input);
    protected:
    private:
};

#endif // PLUGBOARD_HPP
