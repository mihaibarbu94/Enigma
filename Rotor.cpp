#include "Rotor.hpp"
#include "Encode.hpp"
#include <cstring>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <stdlib.h>


using namespace std;

Rotor::Rotor(const char *fileName){
    std::cout << "Hellorotor"<< std::endl;
    //TODO: should put the file manipulation in Utils
    rotorConfig = new int[26];
    int input;
    std::cout << "Hello2rotor"<< std::endl;
    ifstream inputFile;
    inputFile.open(fileName);
    if(inputFile.bad()){
        const string errorMessage =  "ERROR: could not open rotor file.";
        inputFile.close();
		cerr << errorMessage << endl;
		exit (EXIT_FAILURE);
    }

    //  Parse the file characters and add them into the appropriate structure
    std::cout << "Hello3"<< std::endl;
	while(inputFile >> input){
        int i = 0;
		if(!(0 <= input || input < Encode::ALPHABET_SIZE) || i > Encode::ALPHABET_SIZE){
			const string errorMessage =  "ERROR: non-supported character in the rotor file.";
			cerr << errorMessage << endl;
            exit (EXIT_FAILURE);
		}
		rotorConfig[i] = input;
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
