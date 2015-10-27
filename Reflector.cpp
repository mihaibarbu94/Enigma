#include "Reflector.hpp"

int Reflector::encode(int input){
    return (input + ALPHABET_SIZE / 2) % ALPHABET_SIZE;
}
