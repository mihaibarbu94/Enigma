#include "Reflector.hpp"
#include "Encode.hpp"

Reflector::Reflector(){

}

int Reflector::encode(int input){
    //for (int i = 0; i < Encode::ALPHABET_SIZE; ++i){
    //    reflectorConfig[i] = encode(i);
    //}
    return (input + 13) % 26;
}
