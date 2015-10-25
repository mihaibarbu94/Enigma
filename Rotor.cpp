#include "Rotor.hpp"
#include "Encode.hpp"
#include <cstring>
#include <fstream>

using namespace std;

Rotor::Rotor(const char *fileName){
    ifstream inputFile;
    inputFile.open(fileName);
    if(inputFile.bad()){
        const string errorMessage =  "ERROR: could not open rotor file.";
		throw std::invalid_argument(errorMessage);
    }

    //  Parse the file characters and add them into the appropriate structure
	while(inputFile >> y){
		if(!(0 <= y || y < Encode::ALPHABET_SIZE)){
			const string errorMessage =  "ERROR: non-supported character in the rotor file.";
			throw std::invalid_argument(errorMessage);
		}
		int i = 0;
		rotorConfig[i] = y;
		++i;
	}


    inputFile.close();
    numOfRotations = 0;

}
int Rotor::getNumOfRotations(){
    return numOfRotations;
}

void Rotor::setNumOfRotations(int number){
    numOfRotations = number;
}


int Rotor::encode(int input){
    return input;
}

int Rotor::encodeBackwords(int input){
    return input;
}

bool Rotor::hasFullyRotated(){
	return numOfRotations == Encode::ALPHABET_SIZE;
}


void Rotor::rotate(){
	++numOfRotations;
}
