#ifndef ENCODE_HPP
#define ENCODE_HPP

#include "Utils.hpp"
#include "Rotor.hpp"
#include "Plugboard.hpp"
#include "Reflector.hpp"
#include <vector>
#include <memory>
#include <iostream>

class Encode{
    public:
        Encode(char** rotorFiles,
               const char* plugBoardFile,
               int numOfRotorFiles);
		char encryptChar(char c);
    private:
        int numOfRotorFiles;
        void rotateRotors();
        Plugboard *plugboard;
		Reflector *reflector;
		std::vector<std::shared_ptr<Rotor>> rotors;
};

#endif // ENCODE_HPP
