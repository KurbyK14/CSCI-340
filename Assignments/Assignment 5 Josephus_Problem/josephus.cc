/*	Jacob Kurbis (Z1945650)
	CSCI 340: Data Structures Section: 0003
	Assignment 5	Due: 02/27/2023
	
	I certify that this is my own work and where appropriate an extension 
	of the starter code provided for the assignment.
*/

#include "josephus.h"

#include <list>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <getopt.h>
#include <iomanip>


void print_underlined_string(const std::string &message);
void print_list(const std::list<std::string> &collection, const unsigned &eliminations, int num_cols);


/**
* Print a 'Usage' message and exit(1).
*
* @param a0 The name of the command to include in the usage message.
*****************************************************************************/
static void usage(const char *a0)
{
    std::cerr << "Usage: " << a0 << " [-n number of people] [-m modulus] [-p print frequency] [-c print columns]" << std::endl;
    exit(1);
}


/**
* Create a std::list of people with generated ID/names and reduce the
* list as per the Josephus problem algorithm.
*****************************************************************************/
int main(int argc, char **argv)
{
    unsigned num_people = 41;       // The number of people to start with
    unsigned modulus = 3;           // The count used to determine the elimination
    unsigned print_frequency = 13;  // How often to print the state of the system
    unsigned num_cols = 12;         // Number of colums to print per line

    int opt;
    while ((opt = getopt(argc, argv, "n:m:p:c:")) != -1)
    {
        switch (opt)
        {
        case 'n':
            std::istringstream(optarg) >> num_people;
            break;
        case 'm':
            std::istringstream(optarg) >> modulus;
            break;
        case 'p':
            std::istringstream(optarg) >> print_frequency;
            break;
        case 'c':
            std::istringstream(optarg) >> num_cols;
            break;
        default:
            usage(argv[0]);
        }
    }

    if (optind < argc)
        usage(argv[0]); // If we get here, there was extra junk on command line


    //Create a list
    std::list<std::string> p;

    //Generate values for list of people
    std::generate_n(std::back_inserter(p), num_people, SEQ(num_people));

    // Print the initial list
    print_list(p, 0, num_cols);
    std::cout << std::endl;

    //Perform the eliminations
    unsigned int eliminations = 0;
    auto it = p.begin();

    while(p.size() > 1)
    {   
        //Skip the modulus number of people
        for(unsigned i = 0; i < modulus - 1; ++i)
        {
            ++it;

            //If the end of the list is reached, start at the beginning
            if(it == p.end()) it = p.begin();
            
        }

        //Erase the person at the iterator
        it = p.erase(it);

        //If the end of the list is reached, start at the beginning
        if(it == p.end()) it = p.begin();

        ++eliminations;

        //Print the list if the print frequency is reached
        if(eliminations % print_frequency == 0)
        {
            print_list(p, eliminations, num_cols);
            std::cout << std::endl;
        }

    }

    //Print the final list
    std::cout << "Eliminations Completed" << std::endl;
    print_list(p, eliminations, num_cols);
    

  return 0;
}


/**
 * @brief: Prints a string with an underline
 *
 * @param message: The string to be printed 
 */
void print_underlined_string(const std::string &message)
{
    //Get the length of the message
    const size_t message_length = message.length();

    //Printing message with underline
    std::cout << message << std::endl;
    std::cout << std::string(message_length, '-') << std::endl;
}


/**
 * @brief: Prints a list of people
 *
 * @param collection: The list of people to be printed
 * @param eliminations: The number of eliminations that have been performed
 * @param num_cols: The number of columns to print per line 
 */
void print_list(const std::list<std::string> &collection, const unsigned &eliminations, int num_cols)
{
    //Printing the title
    if(eliminations == 0)
    {
        print_underlined_string("Initial group of people");
    }
    else
    {
        print_underlined_string("After eliminating " + std::to_string(eliminations) + " people");
    }

    //Printing the list
    auto it = collection.begin();
    auto last_element = std::prev(collection.end());//Will get the value of the last element in the list right before .end()
    int i = 0;

    while(it != collection.end())
    {
        //Prints a new line if the number of columns is reached
        if(i == num_cols)
        {
            i = 0;
            std::cout << std::endl;
        }
        
        //Prints the last element without a comma
        if(i < num_cols - 1)
        {
            if(it == last_element)
            {
                std::cout << *it++;
                i++;
            }
            //Prints the rest of the elements with a comma
            else
            {
                std::cout << *it++ << ", ";
                i++;
            }
        }
        //Prints the last element without a comma
        else
        {
            std::cout << *it++;
            i++;
        }
        
    }

    //Prints a new line if the number of columns is not reached
    if(i != 0)
    {
        std::cout << std::endl;
    }
    
}