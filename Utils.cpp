#include "Utils.hpp"

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
    return 0 <= num && num < ALPHABET_SIZE;
}

int charToInt(char c){
    return c - 'A';
}

int intToChar(int i){
    return i + 'A';
}

