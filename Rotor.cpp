#include "Rotor.hpp"

using namespace std;

Rotor::Rotor(const char *fileName){
    //rotorConf = new std::vector<int>;

    //std::cout << mapToLetters<< std::endl;

    //ifstream inputFile;
    std::ifstream fin(fileName);
    //  Parse the file characters and add them into the appropriate structure
    int i = 0;
    int input;
	while(fin >> input){
		/*if(!(0 <= input || input < Encode::ALPHABET_SIZE) || i > Encode::ALPHABET_SIZE){
			const string errorMessage =  "ERROR: non-supported character in the rotor file.";
			cerr << errorMessage << endl;
            exit (EXIT_FAILURE);
		}*/
		rotorConfig[i++] = input;
	}
    //inputFile.close();
    numOfRotations = 0;
}

int Rotor::encode(int input){
    return rotorConfig[input];
}

int Rotor::encodeBackwords(int input){
    for (int i = 0; i < 26; i++){
        if (input == rotorConfig[i]){
            return i;
        }
    }
}

bool Rotor::hasFullyRotated(){
	return numOfRotations % 26 == 0;
}

void Rotor::rotate(){
    int rotorConfigCopy[26];
    for (int i = 0; i < 26; i++){
        rotorConfigCopy[i] = rotorConfig[i];
    }
    for(int i = 0; i < 26; i++) {
        rotorConfig[(26 + i - 1) % 26] = (26 + rotorConfigCopy[i] - 1) % 26;
    }
	++numOfRotations;
}
