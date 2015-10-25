#include "Components.hpp"
#include "Encode.hpp"

Components::Components(){
    mapToLetters = new int[Encode::ALPHABET_SIZE];
    mapToLetters[Encode::ALPHABET_SIZE] ={0};
}

