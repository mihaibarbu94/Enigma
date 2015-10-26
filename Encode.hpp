#ifndef ENCODE_HPP
#define ENCODE_HPP

#include "Utils.hpp"
#include <iostream>
#include "Rotor.hpp"
#include "Plugboard.hpp"
#include "Reflector.hpp"
#include <vector>
#include <memory>

class Encode{
    public:
        Encode(char** rotorFiles , const char* plugBoardFile,
               int numOfRotorFiles);
		char encryptChar(char c);
		static const int ALPHABET_SIZE = 26;
    private:
        int numOfRotorFiles;
        void rotateRotors();
        Plugboard *plugboard;
		Reflector *reflector;
		std::vector<std::shared_ptr<Rotor>> rotors;
};

#endif // ENCODE_HPP
