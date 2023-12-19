# 	Jacob Kurbis (Z1945650)
#	CSCI 340: Data Structures Section: 0003
#	Assignment 8	Due: 03/27/2023
#	
#	I certify that this is my own work and where appropriate an extension 
#	of the starter code provided for the assignment.

CXXFLAGS+=-std=c++11 -Wall -Wextra -Werror -pedantic -I.

all: binarytree

binarytree: binarytree.cc btree.h node.h
	g++ $(CXXFLAGS) -o binarytree $^

clean:
	rm -f binarytree *.o

rebuild: clean all