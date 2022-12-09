CXX = g++

main: main.cpp
	g++ -o $@ $<
	cat test0.txt | ./$@ 
	cat test.txt | ./$@ 

final: main
	cat final.txt | ./$<

all: main

clean :
	-rm main