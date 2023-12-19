.DEFAULT_GOAL := lab03pt1.exe

lab03pt1.o: lab03pt1.cc
	g++ -c lab03pt1.cc -Wall -std=c++11

lab03pt1.exe: lab03pt1.o
	g++ -o lab03pt1.exe lab03pt1.o -Wall -std=c++11

clean:
	rm *.o lab03pt1.exe