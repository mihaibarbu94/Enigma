#ifndef ROTOR_HPP
#define ROTOR_HPP

#include "Components.hpp"

class Rotor : public Components{
    public:
        Rotor(const char *fileName);
        virtual int encode(int input);
        int encodeBackwords(int input);
        bool hasFullyRotated();
        void rotate();
        int getNumOfRotations();
        void setNumOfRotations(int number);
        int rotorConfig[];

    protected:
    private:
        int numOfRotations;

};

#endif // ROTOR_HPP
