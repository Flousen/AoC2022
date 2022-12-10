CXX = g++

main: main.cpp
	g++ -o $@ $<
	cat test.txt | ./$@ 

final: main
	cat final.txt | ./$<

test: main
	cat test.txt | ./$<

all: main

clean :
	-rm main