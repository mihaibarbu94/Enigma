# edit this makefile so that running make compiles your enigma program
CXX = g++
CXXFLAGS = -std=c++11 -g

enigma: Main.o Utils.o Rotor.o Encode.o Plugboard.o Reflector.o
	g++ -std=c++11 -g -o enigma Main.o Utils.o Rotor.o Encode.o Plugboard.o Reflector.o
Main.o: Encode.o

Rotor.o: Components.hpp

Encode.o: Rotor.o Plugboard.o Reflector.o

Plugboard.o: Components.hpp

Reflector.o: Components.hpp

clean:
	rm -rf enigma *.o

.PHONY: clean
