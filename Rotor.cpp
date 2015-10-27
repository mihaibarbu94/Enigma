#include "Rotor.hpp"

using namespace std;

Rotor::Rotor(const char *fileName){

    rotorConfig    = inputRotorFile(fileName);
    numOfRotations = 0;
}

int Rotor::encode(int input){
    return rotorConfig[input];
}

int Rotor::encodeBackwords(int input){
    for (int i = 0; i < ALPHABET_SIZE; ++i){
        if (input == rotorConfig[i]){
            return i;
        }
    }
}

bool Rotor::hasFullyRotated(){
	return numOfRotations % ALPHABET_SIZE == 0;
}

void Rotor::rotate(){
    int rotorConfigCopy[ALPHABET_SIZE];
    for (int i = 0; i < ALPHABET_SIZE; ++i){
        rotorConfigCopy[i] = rotorConfig[i];
    }
    for(int i = 0; i < ALPHABET_SIZE; ++i){
        rotorConfig[(ALPHABET_SIZE + i - 1) % ALPHABET_SIZE] =
                    (ALPHABET_SIZE + rotorConfigCopy[i] - 1) % ALPHABET_SIZE;
    }
	++numOfRotations;
}
