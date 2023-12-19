# 	Jacob Kurbis (Z1945650)
#	CSCI 340: Data Structures Section: 0003
#	Assignment 4	Due: 02/20/2023
#	
#	I certify that this is my own work and where appropriate an extension 
#	of the starter code provided for the assignment.
#

CXXFLAGS+=-std=c++11 -Wall -Wextra -Werror -pedantic -I.

all: stack

stack: main.cc stack.h rational.h rational.cc
	g++ $(CXXFLAGS) -o stack $^

clean:
	rm -f stack *.o

rebuild: clean all