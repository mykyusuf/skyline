all: myk

myk:
	g++ -o exe Board.cpp main.cpp -std=c++11

clean:
	rm *.o