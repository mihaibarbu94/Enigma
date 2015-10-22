# edit this makefile so that running make compiles your enigma program

enigma: Main.o Components.o
	g++ -std=c++11 Main.o Components.o -o enigma

Main.o: Main.cpp Components.cpp
	g++ -c -std=c++11 Main.cpp Components.cpp

clean:
	rm -rf enigma *.o

.PHONY: clean
