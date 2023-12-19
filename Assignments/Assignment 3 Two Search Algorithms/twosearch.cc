/* 	Jacob Kurbis (Z1945650)
	CSCI 340: Data Structures Section: 0003
	Assignment 3	Due: 02/13/2023
	
	I certify that this is my own work and where appropriate an extension 
	of the starter code provided for the assignment.
*/

#include "twosearch.h"
#include <getopt.h>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
#include <iterator>


/**
* see: 
* https://en.wikipedia.org/wiki/Usage_message
* https://www.ibm.com/docs/en/aix/7.2?topic=commands-usage-statements
*
* @param a0 The value of argv[0] (the name of the command) so that it 
*   can be printed.
*
* @note This function will terminate the application via exit(1).
******************************************************************************/
static void usage(const char *a0)
{
    std::cerr << "Usage: " << a0 << " [-l rand_low] [-h rand_high] [-a a_size] [-b b_size] [-x a_seed] [-y b_seed] [-c print_cols] [-w col_width]" << std::endl;
    std::cerr << "    rand_low   = rand() low bound (default=1)" << std::endl;
    std::cerr << "    rand_high  = rand() high bound (default=1000)" << std::endl;
    std::cerr << "    a_size     = size of vector A (default=200)" << std::endl;
    std::cerr << "    b_size     = size of vector B (default=100)" << std::endl;
    std::cerr << "    a_seed     = random seed for vector A (default=1)" << std::endl;
    std::cerr << "    b_seed     = random seed for vector B (default=3)" << std::endl;
    std::cerr << "    print_cols = number of colums per line (default=16)" << std::endl;
    std::cerr << "    col_width  = printed column value width (default=4)" << std::endl;
    exit(1);
} // End of usage()

/**
* Parse the command-line args, create and sort vector A, create vector B,
* search vector A for those elements appearing in vector B using both
* a linear and binary search, and print the hit-rate (the percentage of 
* items in B that have been located in A.)
*
* If an invalid command-line arg is encountered, print a Usage statement 
* and terminte with an exit-status of 1.
*
* @return zero
******************************************************************************/
int main(int argc, char **argv)
{
    // Demonstrate the use of getopt() to override default config parameters 
    int rand_low = 1;
    int rand_high = 1000;
    int a_size = 200;
    int b_size = 100;
    int a_seed = 1;
    int b_seed = 3;
    int print_cols = 16;
    int col_width = 4;

    int opt;
    // see: http://faculty.cs.niu.edu/~winans/CS340/2022-sp/#getopt
    while ((opt = getopt(argc, argv, "a:b:c:h:l:w:x:y:")) != -1)
    {
        switch(opt)
        {
        case 'a':
            // see https://en.cppreference.com/w/cpp/string/basic_string/stol
            a_size = std::stoi(optarg); // override the default for a_size
            break;

        case 'b':
            b_size = std::stoi(optarg);
            break;
        case 'c':
            print_cols = std::stoi(optarg);
            break;
        case 'h':
            rand_high = std::stoi(optarg);
            break;
        case 'l':
            rand_low = std::stoi(optarg);
            break;
        case 'w':
            col_width = std::stoi(optarg);
            break;
        case 'x':
            a_seed = std::stoi(optarg);
            break;
        case 'y':
            b_seed = std::stoi(optarg);
            break;
            
        default:
            // got an arg that is not recognized...
            usage(argv[0]);     // pass the name of the program so it can print it
        }
    }

    // Make sure there are not any more arguments (after the optional ones)
    if (optind < argc)
        usage(argv[0]);

    // Add application logic here...
    std::vector<int> A(a_size);
    std::vector<int> B(b_size);

    init_vector(A, a_seed, rand_low, rand_high);
    init_vector(B, b_seed, rand_low, rand_high);

    std::cout << "A vector:" << std::endl;
    print_vector(A, print_cols, col_width);
    sort_vector(A);

    std::cout << "A vector sorted:" << std::endl;
    print_vector(A, print_cols, col_width);

    std::cout << "B vector:" << std::endl;
    print_vector(B, print_cols, col_width);

    //Linear search
    auto found = search_vector(B, A, linear_search);
    std::cout <<"Linear Search: ";
    print_stat(found, b_size);

    //Binary search
    found = search_vector(B, A, binary_search);
    std::cout <<"Binary Search: ";
    print_stat(found, b_size);

    return 0;

} // End of main()

/**
 * @brief Initializes a vector with random numbers
 * 
 * @param vec: vector to be initialized
 * @param seed: seed for the random number generator
 * @param lo: lower bound for the random numbers
 * @param hi: upper bound for the random numbers
 */
void init_vector(std::vector<int> &vec, int seed, int lo, int hi)
{
    //Initializing the random number generator
    srand(seed);

    //Generating random numbers for the vector
    for (unsigned int i = 0; i < vec.size(); i++)
    {
        vec[i] = rand() % (hi - lo + 1) + lo;
    }   
}

/**
 * @brief Prints the elements of a vector in a table
 * 
 * @param v: vector to be printed 
 * @param cols: number of columns for the table
 * @param width: width of each column
 */
void print_vector(const std::vector<int> &v, int print_cols, int col_width)
{
    //Getting the number of rows and header/footer length
    int rows = (v.size() + print_cols - 1) / print_cols,
        head_foot = (col_width + 2) * print_cols + 1;

    //Printing Header
    std::cout << std::setfill('-') << std::setw(head_foot) << "" << std::endl;

    //Printing Vector
    for(int i = 0; i < rows; ++i)
    {
        std::cout << "|";//Printing the left side border

        for(int j = 0; j < print_cols; ++j)
        {
            unsigned int pos = i * print_cols + j;

            //Check if the position is within the bounds of the vector
            if(pos < v.size())
            {
                std::cout << std::setfill(' ') << std::setw(col_width) << v[pos] << " |";
            }
            else
            {
                std::cout << std::setfill(' ') << std::setw(col_width) << " " << " |";
            }
        }
        std::cout << std::endl;
    
    }

    //Printing Footer
    std::cout << std::setfill('-') << std::setw(head_foot) << "" << std::endl;
}

/**
 * @brief Sorts a vector in ascending order
 * 
 * @param vec: vector to be sorted
 */
void sort_vector(std::vector<int> &vec)
{
    //Sorting the vector
    std::sort(vec.begin(), vec.end());
}

/**
 * @brief Searches for elements from one vector in another vector
 * 
 * @param v1: vector whose elements are being searched
 * @param v2: vector being searched
 * @param p: The search function to be used for linear or binary search
 * @return int: number of elements found in v2
 */
int search_vector(const std::vector<int> &v1, const std::vector<int> &v2, bool (*p)(const std::vector<int> &, int))
{
    int value = 0;

    //Loop through the vector and search for each element
    for (unsigned int i = 0; i < v1.size(); i++)
    {
        if (p(v2, v1[i]))//If the current element in the first vector is found in the second vector
        {
            value++;
        }
    }

    return value;
}

/**
 * @brief Prints the percentage of successful searches
 * 
 * @param found: the number of successful searches
 * @param total: the total number of searches
 */
void print_stat(int found, int total)
{
    //Calculate and print the percentage of successful searches
    std::cout << "Percent of Successful Searches = " << std::fixed << std::setprecision(2) << (float)found / total * 100 << "%"  << std::endl;
}

/**
 * @brief Performs a linear search on a vector
 * 
 * @param v: the vector being searched
 * @param x: the element being searched for
 * @return true: if the element is found
 * @return false: if the element is not found
 */
bool linear_search(const std::vector<int> &v, int x)
{
    return std::find(v.begin(), v.end(), x) != v.end();
}

/**
 * @brief Performs a binary search on a vector
 * 
 * @param v: the vector being searched 
 * @param x: the element being searched for
 * @return true: if the element is found
 * @return false: if the element is not found
 */
bool binary_search(const std::vector<int> &v, int x)
{
    return std::binary_search(v.begin(), v.end(), x);
}