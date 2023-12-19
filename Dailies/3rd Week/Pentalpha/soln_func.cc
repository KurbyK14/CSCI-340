#include <iostream>
#include <vector>
#include <algorithm>

bool pentalpha(int place_order[])
{
    int board[][] = {{5,6},
                     {3,7},
                     {4,8},
                     {1,9},
                     {1,8},
                     {0,9},
                     {0,8},
                     {1,4},
                     {0,4},
                     {1,0}};

    bool filled[10] = {0,0,0,0,0,0,0,0,0,0};

    int previous_vert = 0;
    int current_vert = place_order[0];
    
    if(board[current_vert][0] == false)
    {
        //place the chip
        previous_vert = current_vert;
        current_vert = board[current_vert][0];
    }
    else if (board[current_vert][1] == false)
    {
        previous_vert = current_vert;
        current_vert = board[current_vert][1];
    }
    else
    {
        current_vert = previous_vert;
    }

    

}
