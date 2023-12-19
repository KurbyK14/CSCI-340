/* 	Jacob Kurbis (Z1945650)
	CSCI 340: Data Structures Section: 0003
	Assignment 2	Due: 02/06/2021
	
	I certify that this is my own work and where appropriate an extension 
	of the starter code provided for the assignment.
*/

#include "matrix.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cassert>

using namespace std;


/**
 * @brief Constructs a new matrix object
 * 
 * @param rows: number of rows in the matrix
 * @param cols: number of columns in the matrix
 */
matrix::matrix(unsigned int rows, unsigned int cols)
{
    resize(rows, cols);//Resizing the matrix to the correct size
}

/**
 * @brief Resizes the matrix
 * 
 * @param rows: number of rows in the matrix
 * @param cols: number of columns in the matrix 
 */
void matrix::resize(unsigned int rows, unsigned int cols)
{
    mat.resize(rows);//Resizing the vector to have row elements
    for(unsigned int i = 0; i < mat.size(); i++)//Resizing each element to have col elements
    {
        mat[i].resize(cols);
    }
}

/**
 * @brief Loads the matrix from a file
 * 
 * @param &is: reference to the input stream from which to read the matrix
 */
void matrix::load(istream &is)
{
    int value, rows, cols;
    is >> rows >> cols;//Storing the number of rows and columns respectively
    resize(rows, cols);//Resizing the matrix to the correct size

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            is >> value;//Setting the values of the matrix one at-a-time
            at(i, j) = value;
        }
    }
}

/**
 * @brief Prints the matrix
 * 
 * @param colWidth: width for each column
 */
void matrix::print(int colWidth) const
{
    int border_len = (colWidth + 1) * getCols() + getCols() + 1;//Calculating the length of the header and footer

    cout << getRows() << " x " << getCols() << endl//Printing the number of rows and columns title
         << setfill('-') << setw(border_len) << "" << endl;//Printing Header

    for(unsigned int i = 0; i < getRows(); i++)
    {
        cout << "|";//Printing the side left border
        for(unsigned int j = 0; j < getCols(); j++)
        {
            cout << setfill(' ') << setw(colWidth) << mat[i][j] << " |";//Printing the matrix and side right border
        }
        cout << endl;
    }

    cout << setfill('-') << setw(border_len) << "-" << endl;//Printing Footer
    
}

/**
 * @brief Multiplies and returns the value at the specified row and column of the matrix
 * 
 * @param &rhs: the right-hand-side of the operator of the matrix to multiply with
 * 
 * @return product: the result of the multiplication of matrices 
 */
matrix matrix::operator*(const matrix &rhs) const
{
    //To make certain that the two matrices have compatible dimensions for multiplication.
    assert(getCols() == rhs.getRows() && "The matrices cannot be multiplied, they do not have compatible dimensions");

    matrix product(getRows(), rhs.getCols()); //Local matrix to store the product of the two matrices

    for (unsigned int i = 0; i < product.getRows(); i++)//Nested for loops to iterate through the matrices
    {
        for (unsigned int j = 0; j < product.getCols(); j++)
        {
            for (unsigned int k = 0; k < getCols(); k++)
            {
                product.at(i,j) += at(i,k) * rhs.at(k,j);//Multiplying the matrices
            }
            
        }
    }
    return product;//Returning the new product
}