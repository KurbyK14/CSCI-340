# 	Jacob Kurbis (Z1945650)
#	CSCI 340: Data Structures Section: 0003
#	Assignment 9	Due: 04/05/2023
#	
#	I certify that this is my own work and where appropriate an extension 
#	of the starter code provided for the assignment.

CXXFLAGS += -std=c++11 -Wall -Wextra -Werror -pedantic -I.

all: binarysearchtree

binarysearchtree: bst.o
	g++ $(LDFLAGS) -o binarysearchtree bst.o

bst.o: bst.cc bst.h node.h btree.h binarysearchtree.h
	g++ $(CXXFLAGS) -c bst.cc

clean:
	rm -f binarysearchtree *.o

rebuild: clean all