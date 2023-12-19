#ifndef GRAPH_H
#define GRAPH_H

/*  Jacob Kurbis (Z1945650)
    CSCI 340: Data Structures Section: 0003
    Assignment 11	  Due: 04/26/2023
	
    I certify that this is my own work and where appropriate an extension 
    of the starter code provided for the assignment.
*/

#include <list>
#include <vector>

class Graph {
 private:
  int                          size;
  std::vector<std::list<int> > adj_list;
  std::vector<char>            labels;
  void                         Depthfirst(int, std::vector<bool>&, std::vector<char>&, std::vector<std::pair<char, char>>&);//Added container parameters

 public:
  Graph(const char* filename);
  ~Graph();
  int  Getsize() const;
  void Traverse();
  void Print() const;
};

#endif  // GRAPH_H
