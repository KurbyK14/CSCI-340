# 	Jacob Kurbis (Z1945650)
#	CSCI 340: Data Structures Section: 0003
#	Assignment 10	Due: 04/12/2023
#	
#	I certify that this is my own work and where appropriate an extension 
#	of the starter code provided for the assignment.

CXXFLAGS += -std=c++11 -Wall -Wextra -Werror -pedantic -I.

all: hash

hash: hashmain.o htable.cc
	g++ $(LDFLAGS) -o hash hashmain.o htable.cc

hashmain.o: hashmain.cc hashmain.h htable.h entry.h
	g++ $(CXXFLAGS) -c hashmain.cc

clean:
	rm -f hash *.o

rebuild: clean all