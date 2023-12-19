.DEFAULT_GOAL := lab01.exe

lab01.o: lab01.cc
	g++ -c lab01.cc -Wall -std=c++11

lab01.exe: lab01.o
	g++ -o lab01.exe lab01.o -Wall -std=c++11

clean:
	rm *.o lab01.exe