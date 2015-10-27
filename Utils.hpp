#ifndef UTILS_HHH
#define UTILS_HHH

#include <string.h>

static const int ALPHABET_SIZE = 26;

bool isRotorFile(const char *fileName);
bool isPlugboardFile(const char* fileName);
bool isValidRotorInput (int num);
int charToInt(char c);
int intToChar(int i);

#endif // UTILS_HHH
