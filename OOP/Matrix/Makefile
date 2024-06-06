matrix : Matrix.o main.o
	g++ Matrix.o main.o -o matrix

main.o : Matrix.hpp main.cpp
	g++ -c main.cpp

matrix.o : Matrix.hpp Matrix.cpp
	g++ -c Matrix.cpp

clean:
	rm matrix *.o
