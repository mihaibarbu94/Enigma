#include "Plugboard.hpp"

using namespace std;

Plugboard::Plugboard(const char *fileName){
    int input1;
    int input2;

    for (int i = 0; i < ALPHABET_SIZE; i++){
        plugboardConfig[i] = i;
    }

    int *inputFileValues = inputPLugboardFile(fileName);

    int i = 1;
    while (i < inputFileValues[0]){
        input1 = inputFileValues[i++];
        input2 = inputFileValues[i++];
        plugboardConfig[input1] = input2;
        plugboardConfig[input2] = input1;
    }
}

int Plugboard::encode(int input){
    return plugboardConfig[input];
}

