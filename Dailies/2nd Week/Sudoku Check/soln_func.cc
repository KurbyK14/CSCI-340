#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

bool valid_sudoku(vector<vector<int>> &s)
{
    //Row check
    for(int i = 0; i < 9; i++)
    {
        vector<bool> row(9, false);//Vector of size 9 with all elements set to false
        for(int j = 0; j < 9; j++)
        {
            if(s[i][j] != 0)//Checks if the element at index s[i][j] is not 0
            {
                if(row[s[i][j] - 1])//Checks if the element at index s[i][j] - 1 is true
                {
                    return false;
                }
                row[s[i][j] - 1] = true;//Sets the element at index s[i][j] - 1 to true
            }
        }
    }


    //Column check
    for(int j = 0; j < 9; j++)//Iterates through the columns first with j variable
    {
        vector<bool> col(9, false);
        for(int i = 0; i < 9; i++)//Iterates the rows second with i variable
        {
            if(s[i][j] != 0)
            {
                if(col[s[i][j] - 1])
                {
                    return false;
                }
                col[s[i][j] - 1] = true;
            }
        }
    }

    
    //Box check
    for (int i = 0; i < 9; i++)
    {
        vector<bool> box(9, false);
        for(int j = 0; j < 9; j++)
        {
            if(s[i][j] != 0)
            {
                if(box[s[i][j] - 1])
                {
                    return false;
                }
                box[s[i][j] - 1] = true;
            }
        }
    }


    return true;
}