#include "Encode.hpp"

using namespace std;

Encode::Encode(char** rotorFiles , const char* plugboardFile,
               int numOfRotorFiles)
{
    this->numOfRotorFiles = numOfRotorFiles;
    for(int i = 0; i < numOfRotorFiles; ++i){
        std::shared_ptr<Rotor> rotor (new Rotor(rotorFiles[i]));
        rotors.push_back(rotor);
    }

    // Create the plugboard
	plugboard = new Plugboard(plugboardFile);

		// Create the reflector
	reflector = new Reflector();
}

char Encode::encryptChar(char c){
    int enc;
    enc = charToInt(c);
    // Plugboard first time
    enc = plugboard->encode(enc);

    // Rotors encoding
    for(int i = 0; i < numOfRotorFiles; i++){
        enc = rotors[i]->encode(enc);
    }

    // Reflector
    enc = reflector->encode(enc);

    // Rotors encoding backwords
    for(int i = numOfRotorFiles - 1; i >= 0; i--){
        enc = rotors[i]->encodeBackwords(enc);
    }

    // Plugboard second time
    enc = plugboard->encode(enc);

    // Rotate rotors
    if(numOfRotorFiles > 0){
        rotateRotors();
    }

    return intToChar(enc);
}

void Encode::rotateRotors() {
	// Always rotate the first rotor
	rotors[0]->rotate();
	int i = 0;
    while(rotors[i + 1] != NULL && rotors[i]->hasFullyRotated()){
        rotors[++i]->rotate();
    };
	// Rotate the following rotors if necessary
}

