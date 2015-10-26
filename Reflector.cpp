#include "Reflector.hpp"

int Reflector::encode(int input){
    return (input + 13) % 26;
}
