.DEFAULT_GOAL := lab02.exe

lab02.o: lab02.cc
	g++ -c lab02.cc -Wall -std=c++11

lab02.exe: lab02.o
	g++ -o lab02.exe lab02.o -Wall -std=c++11

clean:
	rm *.o lab02.exe