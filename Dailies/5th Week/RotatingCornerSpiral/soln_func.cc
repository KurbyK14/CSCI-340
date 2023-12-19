#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> RotatingCornerSpiral(std::vector<std::vector<int>> &m)
{
    int num_rows = m.size();//number of rows of m;
    int num_cols = m[0].size();//number of columns of m

    //check if m is empty or not a square
    if(num_rows != num_cols)
    {
        return std::vector<int>(0);
    }
    else if(num_rows && num_cols == 1)
    {
        return m[0];
    }

    std::vector<int> spiral_m;//vector to store the spiral
    std::vector<std::vector<bool>> bool_m(m.size(), std::vector<bool>(m[0].size(), false));//vector to keep track of which elements have been visited

    int top_left = m[0][0], top_right = m[0][m[0].size() - 1],//top_left is the top left corner, top_right is the top right corner
        bottom_left = m[m.size() - 1][0], bottom_right = m[m.size() - 1][m[m.size() - 1].size() - 1];//bottom_left is the bottom left corner, bottom_right is the bottom right corner

    int k = 0;//k is the number of elements that have been visited

    //Add the corners to the vector
    spiral_m.push_back(top_left);
    bool_m[0][0] = true;

    spiral_m.push_back(top_right);
    bool_m[0][m[0].size() - 1] = true;

    spiral_m.push_back(bottom_right);
    bool_m[m.size() - 1][m[m.size() - 1].size() - 1] = true;

    spiral_m.push_back(bottom_left);
    bool_m[m.size() - 1][0] = true;

    //While loop to iterate through the square
    while(k < num_rows * num_rows)
    {
        //Traverse the top row to the right
        for(int col = 1; col < num_cols - 1; col++)
        {
            if(bool_m[0][col] == false)
            {
                spiral_m.push_back(m[0][col]);
                bool_m[0][col] = true;
            }
        }

        //Traverse the right column to the bottom
        for(int row = 1; row < num_rows - 1; row++)
        {
            if(bool_m[row][num_cols - 1] == false)
            {
                spiral_m.push_back(m[row][num_cols - 1]);
                bool_m[row][num_cols - 1] = true;
            }
        }

        //Traverse the bottom row to the left
        for(int col = num_cols - 2; col > 0; col--)
        {
            if(bool_m[num_rows - 1][col] == false)
            {
                spiral_m.push_back(m[num_rows - 1][col]);
                bool_m[num_rows - 1][col] = true;
            }
        }

        //Traverse the left column to the top
        for(int row = num_rows - 2; row > 0; row--)
        {
            if(bool_m[row][0] == false)
            {
                spiral_m.push_back(m[row][0]);
                bool_m[row][0] = true;
            }
        }

        k++;
    }

    //If the square is odd or has greater than 1 element, add the middle element to the vector
    if(num_rows % 2 == 1 && num_rows * num_rows > 1)
    {
        spiral_m.push_back(m[num_rows/2][num_rows/2]);
    }

    return spiral_m;
}