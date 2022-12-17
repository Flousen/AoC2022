CXX = g++

main: main.py
	cat test.txt | python main.py

final: main
	cat final.txt | python main.py

test: main
	cat test.txt | python main.py

all: main

clean :
	-rm main