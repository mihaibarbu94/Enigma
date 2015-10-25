# edit this makefile so that running make compiles your enigma program

enigma: Main.o Components.o Utils.o Rotor.o Encode.o Plugboard.o Reflector.o
	g++ -std=c++11 Main.o Components.o Utils.o Rotor.o Encode.o Plugboard.o Reflector.o -o enigma

Main.o: Main.cpp Components.cpp Utils.cpp Rotor.cpp Encode.cpp Plugboard.cpp Reflector.cpp
	g++ -c -std=c++11 Main.cpp Components.cpp Utils.cpp Rotor.cpp Encode.cpp Plugboard.cpp Reflector.cpp

clean:
	rm -rf enigma *.o

.PHONY: clean
