CXX = g++ 

main: main.cpp
	g++ -Wall -std=c++2a -o $@ $<
	cat test.txt | ./$@ 

final: main
	cat final.txt | ./$<

test: main
	cat test.txt | ./$<

all: main

clean :
	-rm main