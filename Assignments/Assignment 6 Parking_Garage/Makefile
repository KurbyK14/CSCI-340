# 	Jacob Kurbis (Z1945650)
#	CSCI 340: Data Structures Section: 0003
#	Assignment 6	Due: 03/06/2023
#	
#	I certify that this is my own work and where appropriate an extension 
#	of the starter code provided for the assignment.

CXXFLAGS+=-std=c++11 -Wall -Wextra -Werror -pedantic -I.

all: parking

parking: parking.cc parking.h
	g++ $(CXXFLAGS) -o parking $^

clean:
	rm -f parking *.o

rebuild: clean all