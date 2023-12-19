/*  Jacob Kurbis (Z1945650)
    CSCI 340: Data Structures Section: 0003
    Assignment 11	  Due: 04/26/2023
	
    I certify that this is my own work and where appropriate an extension 
    of the starter code provided for the assignment.
*/

#include "graph.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>


/**
 * @brief: Perform Depth First Search(DFS) starting at vertex v
 *
 * @param v: the vertex for the Depth First Search
 *
 * @param visited: a reference to a boolean vector, indicating whether a vertex has been visited during DFS or not
 * 
 * @param traversal_order: a reference to a character vector, containing the order in which the vertices were visited during DFS
 * 
 * @param edges: a reference to a pair vector, containing the edges that were traversed during DFS
 */
void Graph::Depthfirst(int v, std::vector<bool>& visited, std::vector<char>& traversal_order, std::vector<std::pair<char, char>>& edges) 
{
    //Mark the current vertex as visited and add it's label to the traversal order
    visited[v] = true;
    traversal_order.push_back(labels[v]);

    //Traverse all adjacent vertices of vertex v
    for(auto it = adj_list[v].begin(); it != adj_list[v].end(); it++)
    {
        //If the adjancency vertex has not been visited yet, add it's edge to the edge list and visit it
        if(!visited[*it])
        {
            edges.push_back(std::make_pair( labels[v], labels[*it]));
            Depthfirst(*it, visited, traversal_order, edges);
        }
    }
    
}


/**
 * @brief: 
 *
 * @param filename:
 */
Graph::Graph(const char* filename)
{
    //Create an if stream object to read the file from
    std::ifstream file(filename);

    if(file.is_open())
    {
        //Read the size of the graph, and resize the adj_list and label vector
        std::string line;
        std::getline(file, line);
        size = std::stoi(line);

        adj_list.resize(size);
        labels.resize(size);

        //Read the labels and add them to the label vector
        std::getline(file, line);
        std::istringstream label_stream(line);

        char label;
        int i = 0;

        while(label_stream >> label)
        {
            labels[i++] = label;
        }

        //Read the adjancency matrix and add edges to the adj_list
        i = 0;
        while(std::getline(file, line))
        {
            std::istringstream matrix_stream(line);
            int j = 0;
            char c;
            matrix_stream >> c;//Skip the row label

            while(matrix_stream >> c)
            {
                //If the character is '1', add the corresponding vertex to the adjancency list
                if(c == '1')
                {
                    adj_list[i].push_back(j);
                }
                j++;
            }
            i++;//Move to the next row in the adjancency matrix
        }
        file.close();
    }
}


/**
 * @brief: Destructor that clears the adjancency list and labels vector
 */
Graph::~Graph()
{
    for( int i = 0; i < size; i++ )
    {
        adj_list[i].clear();
    }

    adj_list.clear();
    labels.clear();

    size = 0;
}


/**
 * @brief: Returns the size of the graph
 * 
 * @return: The number of vertices in the graph
 */
int Graph::Getsize() const 
{ 
    return size; 
}


/**
 * @brief: Traverses the graph in DFS order and prints out the traversal order and edges 
 */
void Graph::Traverse() 
{
    std::vector<bool> visited(size, false);//Vector of visited vertices
    std::vector<char> traversal_order;//Vector of vertices in traversal order
    std::vector<std::pair<char, char>> edges;//Vector of edges in traversal order

    //Traverse each vertex
    for(int i = 0; i < size; i++)
    {
        if(!visited[i])//If the vertex has not been visited, traverse it using DFS
        {
            Depthfirst(i, visited, traversal_order, edges);
        }
    }

    std::cout << "------- traverse of graph ------" << std::endl;

    //Printing out traversal order
    for(auto it = traversal_order.begin(); it != traversal_order.end(); it++)
    {
        std::cout << *it << " ";
    }

    std::cout << std::endl;

    //Printing out edges
    for(auto it = edges.begin(); it != edges.end(); it++)
    {
        std::cout << "(" << it->first << ", " << it->second << ") ";
    }

    std::cout << std::endl << "--------- end of traverse -------" << std::endl << std::endl;
}


/**
 * @brief: Prints out the adj_list representation of the graph
 */
void Graph::Print() const 
{
    std::cout << std::endl << "Number of vertices in the graph: " << size << std::endl << std::endl;

    std::cout << "-------- graph -------" << std::endl;

    //Traverse each vertex and it's neighbors
    for(int i = 0; i < size; i++)
    {
        std::cout << labels[i] << ": ";
        for(auto it = adj_list[i].begin(); it != adj_list[i].end(); it++)
        {
            //Print out neighbors
            if(it == std::prev(adj_list[i].end()))
            {
                std::cout << labels[*it];
            }
            else
            {
                std::cout << labels[*it] << ", ";
            }
            
        }
        std::cout << std::endl;
    }

    std::cout << "------- end of graph ------" << std::endl << std::endl;
}