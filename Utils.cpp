#include "Utils.hpp"

using namespace std;

bool isRotorFile(const char *fileName){
    return strlen(fileName) > 4
        && fileName[strlen(fileName) - 4] == '.'
        && fileName[strlen(fileName) - 3] == 'r'
        && fileName[strlen(fileName) - 2] == 'o'
        && fileName[strlen(fileName) - 1] == 't';
}

bool isPlugboardFile(const char* fileName){
    return strlen(fileName) > 3
        && fileName[strlen(fileName) - 3] == '.'
        && fileName[strlen(fileName) - 2] == 'p'
        && fileName[strlen(fileName) - 1] == 'b';
}

bool isValidRotorInput (int num){
    return (0 <= num && num < ALPHABET_SIZE);
}

int charToInt(char c){
    return c - 'A';
}

int intToChar(int i){
    return i + 'A';
}

int *inputPLugboardFile(const char *fileName){
    ifstream inputFile(fileName);

    if(inputFile.fail()){
        const string errorMessage = "ERROR: could not open rotor file.";
		cerr << errorMessage << endl;
		inputFile.close();
		exit (EXIT_FAILURE);
    }

    int num;
    // first number in array is the number of elements
    int* input = new int[ALPHABET_SIZE + 1];

    int i = 1;
    while(inputFile >> num){
        input[i++] = num;
    }

    input[0] = i - 1; // i - 1 the number of elements in array
    inputFile.close();

    return input;
}

bool isValidInputForReflector(int input){
    if(!(0 <= input || input < ALPHABET_SIZE)){
			const string errorMessage =
                            "ERROR: non-supported character in the rotor file.";
			cerr << errorMessage << endl;
			exit (EXIT_FAILURE);
    }

    return true;
}

int *inputRotorFile(const char *fileName){
    ifstream inputFile(fileName);
    int i = 0;
    int num;
    int* input = new int[ALPHABET_SIZE];

	while(inputFile >> num){
		if(!(0 <= num || num < ALPHABET_SIZE) || i > ALPHABET_SIZE){
			const string errorMessage =
                            "ERROR: non-supported character in the rotor file.";
			cerr << errorMessage << endl;
			inputFile.close();
            exit (EXIT_FAILURE);
		}
		input[i++] = num;
	}
    inputFile.close();

    return input;
}


