# 	Jacob Kurbis (Z1945650)
#	CSCI 340: Data Structures Section: 0003
#	Assignment 11	Due: 04/26/2023
#	
#	I certify that this is my own work and where appropriate an extension 
#	of the starter code provided for the assignment.

CXXFLAGS+=-std=c++11 -Wall -Wextra -Werror -pedantic -I.

all: simplegraph

simplegraph: simplegraph.cc graph.h graph.cc
	g++ $(CXXFLAGS) -o simplegraph $^

clean:
	rm -f simplegraph *.o

rebuild: clean all