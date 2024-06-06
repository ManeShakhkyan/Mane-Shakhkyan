container : main.o myContainer.o
	g++ main.o myContainer.o -o container

main.o : main.cpp
	g++ -c -Wall main.cpp

myContainer.o : myContainer.cpp
	g++ -c -Wall myContainer.cpp

clean :
	rm -rf container *.o 
