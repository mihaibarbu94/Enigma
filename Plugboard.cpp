#include "Plugboard.hpp"

using namespace std;

Plugboard::Plugboard(const char *fileName){
    //TODO: should put the file manipulation in Utils
    ifstream inputFile(fileName);
    if(inputFile.fail()){
        const string errorMessage =  "ERROR: could not open rotor file.";
        inputFile.close();
		cerr << errorMessage << endl;
		exit (EXIT_FAILURE);
    }

    int input1;
    int input2;
    for (int i = 0; i < 26; i++){
        plugboardConfig[i] = i;
    }
    int i = 0;
    while (inputFile >> input1 >> input2){
        plugboardConfig[input1] = input2;
        plugboardConfig[input2] = input1;
    }
}

int Plugboard::encode(int input){
    return plugboardConfig[input];
}

