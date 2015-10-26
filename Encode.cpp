#include "Encode.hpp"
#include "Rotor.hpp"
#include "Plugboard.hpp"
#include "Reflector.hpp"
#include "Utils.hpp"
#include <iostream>

using namespace std;

Encode::Encode(char** rotorFiles , const char* plugboardFile,
               int numOfRotorFiles)
{
    rotors = new Rotor*[numOfRotorFiles];
    // Create the rotors
    for(int i = 0; i < numOfRotorFiles; ++i){
        std::cout << rotorFiles[i] << std::endl;
        rotors[i] = new Rotor(rotorFiles[i]);

    }
    std::cout << "Hello2"<< std::endl;

    // Create the plugboard
	//plugboard = new Plugboard(plugboardFile);
	std::cout << plugboardFile<< std::endl;

		// Create the reflector
	//reflector = new Reflector();
}

char Encode::encryptChar(char c){
    int i;
    i = charToInt(c);
    // Plugboard first time
    i = plugboard->encode(i);

    // Rotors encoding
    for(int i = 0; i < numOfRotorFiles; ++i){
        i = rotors[i]->encode(i);
    }

    // Reflector
    i = reflector->encode(i);

    // Rotors encoding backwords
    for(int i = 0; i < numOfRotorFiles; ++i){
        i = rotors[i]->encodeBackwords(i);
    }

    // Plugboard second time
    i = plugboard->encode(i);

    // Rotate rotors
    if(numOfRotorFiles > 0){
        rotateRotors();
    }

    return intToChar(i);
}

void Encode::rotateRotors() {
	// Always rotate the first rotor
	rotors[0]->rotate();

	// Rotate the following rotors if necessary
	for(int i = 0; i < numOfRotorFiles - 1; ++i){
		if(rotors[i]->hasFullyRotated()){
			rotors[i]->setNumOfRotations(0);
			rotors[i + 1]->rotate();
		}
	}
}

