all: clean main

clean:
	rm main

main:
	clang++ --std=c++2b src/main.cpp -o main -I. -Isrc