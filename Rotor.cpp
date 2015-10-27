#include "Rotor.hpp"

Rotor::Rotor(const char *fileName){
    //  Parse the file characters and add them into the appropriate structure
    ifstream fin(fileName);
    int i = 0;
    int input;
	while(fin >> input){
		if(!(0 <= input || input < ALPHABET_SIZE) || i > ALPHABET_SIZE){
			const string errorMessage =
                            "ERROR: non-supported character in the rotor file.";
			cerr << errorMessage << endl;
			fin.close();
            exit (EXIT_FAILURE);
		}
		rotorConfig[i++] = input;
	}
    fin.close();
    numOfRotations = 0;
}

int Rotor::encode(int input){
    return rotorConfig[input];
}

int Rotor::encodeBackwords(int input){
    for (int i = 0; i < ALPHABET_SIZE; i++){
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
    for (int i = 0; i < ALPHABET_SIZE; i++){
        rotorConfigCopy[i] = rotorConfig[i];
    }
    for(int i = 0; i < ALPHABET_SIZE; i++){
        rotorConfig[(ALPHABET_SIZE + i - 1) % ALPHABET_SIZE] =
                    (ALPHABET_SIZE + rotorConfigCopy[i] - 1) % ALPHABET_SIZE;
    }
	++numOfRotations;
}
