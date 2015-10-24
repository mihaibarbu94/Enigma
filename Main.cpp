#include <stdexcept>
#include <iostream>
#include <fstream>
#include <cstdlib>

#include "Utils.hpp"

using namespace std;

int main(int argc, char **argv)
{
    if(argc < 2){
        cerr << "ERROR: Run the program as ./enigma [rotor.rot] plugboard.pb"
            << endl << "[rotor.rot]: Optional list of valid rotor files."
            << endl << "plugboard.pb: Required valid plugboard file." << endl;
        exit (EXIT_FAILURE);
    }

    int numOfRotorFiles = 0;

    for (int i = 0; i < argc - 1; ++i){
        if (!isRotorFile(argv[i])){
            cerr << "ERROR: incorrect rotor file: " << argv[i]
            << " Please enter a correct file!" << endl;
            exit (EXIT_FAILURE);
        }
        ++numOfRotorFiles;
    }

    const char* plugBoardFile = argv[argc - 1];

    if (!isPlugboardFile(plugBoardFile)){
        cerr << "ERROR: incorrect plugboard file: " << plugBoardFile
            << " Please enter a correct file!" << endl;
            exit (EXIT_FAILURE);
    }


    return EXIT_SUCCES;
}
