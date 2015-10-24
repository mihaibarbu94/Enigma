# edit this makefile so that running make compiles your enigma program

enigma: Main.o Components.o Utils.o Rotor.o
	g++ -std=c++11 Main.o Components.o Utils.o Rotor.o -o enigma

Main.o: Main.cpp Components.cpp Utils.cpp Rotor.cpp
	g++ -c -std=c++11 Main.cpp Components.cpp Utils.cpp Rotor.cpp

clean:
	rm -rf enigma *.o

.PHONY: clean
