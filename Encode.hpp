#ifndef ENCODE_HPP
#define ENCODE_HPP

#include "Rotor.hpp"
#include "Plugboard.hpp"
#include "Reflector.hpp"

class Encode
{
    public:
        Encode(char** rotorFiles , const char* plugBoardFile,
               int numOfRotorFiles);

        // Length of the alphabet
		static const int ALPHABET_SIZE = 26;

		int numOfRotorFiles;

		Plugboard *plugboard;
		Reflector *reflector;
		Rotor **rotors;

		char encryptChar(char c);
		void rotateRotors();
    protected:
    private:
};

#endif // ENCODE_HPP
