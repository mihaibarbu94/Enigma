#include "Plugboard.hpp"
#include "Encode.hpp"
#include <cstring>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <stdlib.h>

using namespace std;

Plugboard::Plugboard(const char *fileName){
    //TODO: should put the file manipulation in Utils
    int input1;
    int input2;
    ifstream inputFile;
    inputFile.open(fileName);
    if(inputFile.bad()){
        const string errorMessage =  "ERROR: could not open rotor file.";
        inputFile.close();
		cerr << errorMessage << endl;
		exit (EXIT_FAILURE);
    }

    while (inputFile >> input1 >> input2){
        int i = 0;

        plugboardConfig[i] = input1;
        boolPlugboardConfig[input1] = true;

        plugboardConfig[i + 1] = input2;
        boolPlugboardConfig[input2] = true;

        i+=2;
    }
}

int Plugboard::encode(int input){
    for (int i = 0; i < Encode::ALPHABET_SIZE; i+=2){
        if (plugboardConfig[i] == input){
            return plugboardConfig[i + 1];
        }
        if (plugboardConfig[i + 1] == input){
            return plugboardConfig[i];
        }
    }
}

