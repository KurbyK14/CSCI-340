# 	Jacob Kurbis
#	Z1945650
#	CSCI 340: Data Structures Section: 0003
#	Assignment 1	Due: 1/28/2021
#	
#	I certify that this is my own work and where appropriate an extension 
#	of the starter code provided for the assignment.
#

# Compiler variables
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Rules to link object code files to create executable file
all: introduction

introduction: introduction.o
	$(CXX) $(CXXFLAGS) -o introduction $^

# Rules to compile source code files to object code
introduction.o: introduction.cc

# Pseudo-target to remove object code and executable files
clean:
	rm -f introduction *.o
