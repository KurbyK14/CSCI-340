# 	Jacob Kurbis (Z1945650)
#	CSCI 340: Data Structures Section: 0003
#	Assignment 7	Due: 03/20/2023
#	
#	I certify that this is my own work and where appropriate an extension 
#	of the starter code provided for the assignment.

CXXFLAGS+=-std=c++11 -Wall -Wextra -Werror -pedantic -I.

all: wordscanner

wordscanner: wordscanner.cc
	g++ $(CXXFLAGS) -o wordscanner $^

clean:
	rm -f wordscanner *.o

rebuild: clean all