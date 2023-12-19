.DEFAULT_GOAL := lab04.exe

lab04.o: lab04.cc
	g++ -c lab04.cc -Wall -std=c++11

lab04.exe: lab04.o
	g++ -o lab04.exe lab04.o -Wall -std=c++11

clean:
	rm *.o lab04.exe