/* 	Jacob Kurbis (Z1945650)
	CSCI 340: Data Structures Section: 0003
	Assignment 6	Due: 03/06/2023
	
	I certify that this is my own work and where appropriate an extension 
	of the starter code provided for the assignment.
*/

#include "parking.h"

#include <iostream>
#include <string>
#include <deque>
#include <stack>

int main()
{
    //Create a parking garage object
    garage g;
    std::string command;

    //Read in commands from the user
    while (std::getline(std::cin, command))
    {
        //Get the transaction type and license plate
        char xact_type;
        std::string license;
        get_input_vals(command, xact_type, license);

        //If xact_type is A, call the arrival function
        if (xact_type == 'A')
        {
            g.arrival(license);
        }
        //If xact_type is D, call the departure function
        else if (xact_type == 'D')
        {
            g.departure(license);
        }
        //Error if xact_type is not A or D
        else
        {
            std::cout << "'" << xact_type << "': invalid action!" << std::endl << std::endl;
        }
    }

    return 0;
}
