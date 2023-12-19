#ifndef PARKING_H
#define PARKING_H

/* 	Jacob Kurbis (Z1945650)
	CSCI 340: Data Structures Section: 0003
	Assignment 6	Due: 03/06/2023
	
	I certify that this is my own work and where appropriate an extension 
	of the starter code provided for the assignment.
*/

#include <iostream>
#include <string>
#include <deque>
#include <stack>

class car
{
public:
    car(int id, const std::string &license) : id(id), license(license) {}

    /// Call this to increment the number of times the car has been moved.
    void move();

    /// @return the number of times that the car has been moved.
    int get_num_moves() const;
	
    /// @return A reference to the license for this car.
    const std::string &get_license() const;

    /// @return A reference to the id for this car.
    const int &get_id() const;//Added this function to get the id of the car

    /**
    * Overload the << so this can print itself as:
    *    Car X with license plate "Y"
    ******************************************************************/
    friend std::ostream& operator<<(std::ostream& lhs, const car& rhs);

private:
    int id;                 ///< The ID number for this car (assigned by the garage)
    std::string license;    ///< license plate of this car.
    int num_moves = {0};    ///< how many times the car was moved within the garage.
};


class garage
{
public:
        garage(size_t limit = 10) : parking_lot_limit(limit) {}

        /// @param license The license of the car that has arrived.                                                           
        void arrival(const std::string &license);

        /// @param license The license of the car that has departed.                                                          
        void departure(const std::string &license);

private:
        int next_car_id = { 1 };
        std::deque<car> parking_lot;
        size_t parking_lot_limit;
};

//Helper function to get the input from the user and parse it into the transaction type and license plate
void get_input_vals(const std::string &line, char &xact_type, std::string &license);


/**
 * @brief: This member function of class car will keep track of the number of times a car has been moved
 */
void car::move()
{
    num_moves++;
}


/**
 * @brief: This member function of class car will return the number of times a car has been moved 
 * 
 * @return num_moves: The number of times the car has been moved
 */
int car::get_num_moves() const
{
    return num_moves;
}


/**
 * @brief: This member function of class car will return the license plate of the car
 * 
 * @return license: The car's license plate
 */
const std::string &car::get_license() const
{
    return license;
}


/**
 * @brief: This member function of class car will return the id of the car
 *         *This member function was added to help get the id of the car for 
 *          the departure member function of the garage class*
 * 
 * @return id: The car's id number
 */
const int &car::get_id() const
{
    return id;
}


/**
 * @brief: This friend function of the class car will overload the << operator so that it can print the car's id and license plate
 *
 * @param lhs: The ostream object
 * @param rhs: The car object
 * 
 * @return lhs: The ostream object
 */
std::ostream& operator<<(std::ostream& lhs, const car& rhs)
{
    lhs << "Car " << rhs.id << " with license plate " << rhs.license;
    return lhs;
}


/**
 * @brief: This member function of the class garage will add a car to the parking lot
 *
 * @param license: The license plate of the car that has arrived
 */
void garage::arrival(const std::string &license)
{
    //Create a new car object and print the arrival message
    car new_car(next_car_id, license);
    std::cout << "Car " << next_car_id << " with license plate " << '"'  << license << '"' << " has arrived." << std::endl;

    //If the parking lot is full, print the message and return
    if (parking_lot.size() == parking_lot_limit)
    {
        std::cout << "    But the garage is full!";
        std::cout << std::endl << std::endl;
        return;
    }

    //If the parking lot is not full, push the new car onto the back of the deque
    //and increment the next car id
    parking_lot.push_back(new_car);
    next_car_id++;

    std::cout << std::endl;
}


/**
 * @brief: This member function of the class garage will remove a car from the parking lot
 *
 * @param license: The license plate of the car that will depart
 */
void garage::departure(const std::string &license)
{   
    std::stack<car> temp_parking_lot;//Temporary stack to hold the cars that are not the car we are looking for
    bool car_found = false;//Flag to check if the car was found

    //Loop through the parking lot to find the car with the license plate
    for (auto it = parking_lot.begin(); it != parking_lot.end(); it++)
    {
        //If the car is found, pop it off the front of the deque and push it onto the stack
        if(it->get_license() == license)
        {
            car_found = true;

            //If the car was moved more than once, print the correct grammar--> times vs time
            if(it->get_num_moves() >= 1)
            {
                std::cout << "Car " << it->get_id() << " with license plate " << '"' <<  license << '"' << " has departed," << std::endl
                          << "    car was moved " << it->get_num_moves() + 1 << " times in the garage." << std::endl;
            }
            else
            {
                std::cout << "Car " << it->get_id() << " with license plate " << '"' <<  license << '"' << " has departed," << std::endl
                          << "    car was moved " << it->get_num_moves() + 1 << " time in the garage." << std::endl;
            }

            parking_lot.pop_front();

            //Push the rest of the cars back onto the deque
            while(!temp_parking_lot.empty())
            {
                parking_lot.push_front(temp_parking_lot.top());
                temp_parking_lot.pop();
                parking_lot.front().move();
            }
            
            std::cout << std::endl;
            return;
        }
        //If the car is not found, push it onto the stack and move it
        else
        {
            temp_parking_lot.push(*it);
            it->move();
            parking_lot.pop_front();
        }
    }
    //If the car was not found, print the error message
    if (!car_found)
        {
            std::cout << "No car with license plate " << '"' << license << '"' << " is in the garage." << std::endl;
            std::cout << std::endl;
            return;
        }
        //If the car was found, push the rest of the cars back onto the deque
        else
        {
            while (!temp_parking_lot.empty())
            {
                parking_lot.push_back(temp_parking_lot.top());
                temp_parking_lot.pop();
                parking_lot.front().move();
            }
        }
}

/**
 * @brief: This helper function will parse the input line and extract the transaction type and license plate.
 *
 * @param line: The line of input from the file
 * @param xact_type: The type of transaction
 * @param license: The license plate of the car
 */
void get_input_vals(const std::string &line, char &xact_type, std::string &license)
{
    //Position of the colon in the string
    unsigned pos = line.find(':');

    //If the colon is not found, set the xact_type to null and clear the license
    if (pos == std::string::npos)//npos is the max value returned by a string member function that searches for a character or substring
    {
        xact_type = '\0';//Sets the xact_type to null
        license.clear();//Clears the license
    }
    //If the colon is found, set the xact_type to the first character in the string 
    //and set the license to the string after the colon
    else
    {
        xact_type = line[0];//Sets the xact_type to the first character in the string
        license = line.substr(pos + 1);//Extracts a substring from after the colon
        license.erase(license.find(':'));//Removes excess colons from the license
    }

}

#endif