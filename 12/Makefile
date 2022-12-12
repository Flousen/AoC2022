CXX = g++

main: main.cpp
	g++ -std=c++20 -o $@ $<
	cat test.txt | ./$@ 

final: main
	cat final.txt | ./$<

all: main

clean :
	-rm main