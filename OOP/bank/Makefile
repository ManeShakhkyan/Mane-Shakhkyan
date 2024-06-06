bank : bankAccount.o bank.o
	g++ bankAccount.o bank.o -o bank

bank.o : bankAccount.hpp bank.cpp
	g++ -c bank.cpp

bankAccount.o : bankAccount.hpp bankAccount.cpp
	g++ -c bankAccount.cpp

clean:
	rm bank *.o
