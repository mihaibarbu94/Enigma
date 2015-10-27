#ifndef UTILS_HHH
#define UTILS_HHH

#include <string.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>

static const int ALPHABET_SIZE = 26;

bool isRotorFile(const char *fileName);
bool isPlugboardFile(const char* fileName);
bool isValidRotorInput (int num);
int charToInt(char c);
int intToChar(int i);
int *inputPLugboardFile(const char *fileName);
bool isValidInputForReflector(int input);
int *inputRotorFile(const char *fileName);

#endif // UTILS_HHH
