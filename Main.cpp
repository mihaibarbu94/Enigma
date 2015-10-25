#include <stdexcept>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <memory>

#include "Encode.hpp"
#include "Rotor.hpp"
#include "Plugboard.hpp"
#include "Reflector.hpp"
#include "Utils.hpp"


using namespace std;

int main(int argc, char **argv){
    if(argc < 2){
        cerr << "ERROR: Run the program as ./enigma [rotor.rot] plugboard.pb"
            << endl << "[rotor.rot]: Optional list of valid rotor files."
            << endl << "plugboard.pb: Required valid plugboard file." << endl;
        exit (EXIT_FAILURE);
    }

    int numOfRotorFiles = argc - 2;
    char** rotorFiles = new char*[numOfRotorFiles];
    for(int i = 0; i < numOfRotorFiles; ++i)
    {
      rotorFiles[i] = new char[50];
    }

    for (int i = 0; i < numOfRotorFiles; ++i){
        if (!isRotorFile(argv[i])){
            cerr << "ERROR: incorrect rotor file: " << argv[i]
            << " Please enter a correct file!" << endl;
            exit (EXIT_FAILURE);
        }
        rotorFiles[i] = argv[i];
    }

    const char* plugboardFile = argv[argc - 1];

    if (!isPlugboardFile(plugboardFile)){
        cerr << "ERROR: incorrect plugboard file: " << plugboardFile
            << " Please enter a correct file!" << endl;
            exit (EXIT_FAILURE);
    }

    try{
        Encode *encode = new Encode(rotorFiles, plugboardFile, numOfRotorFiles);
        char c;
        while (cin >> ws >> c){
            encode->encryptChar(toupper(c));
        }
    }catch (int exception) {
        cerr << exception;
    }


    return 0;
}
