#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

int captured(int knight_r, int knight_c, int pawn_r, int pawn_c)
{
    if(knight_r == pawn_r && knight_c == pawn_c)
    {
        return 0;//Knight and pawn are in the same spot
    }

    std::vector<std::vector<int>> board(8, std::vector<int>(8));//Create a 8x8 board

    std::vector<std::vector<int>> moves = {{2, 1}, {1, 2}, {-2, 1}, {-1, 2}, 
                                        {2, -1}, {1, -2}, {-2, -1}, {-1, -2}};//All possible moves
    
    std::queue<std::pair<int, int>> q;//Queue to store the moves

    q.push({knight_r, knight_c});//Push the knight's position into the queue
    board[knight_r][knight_c] = 0;//Knight's position is 0

    while(!q.empty())
    {
        std::pair<int, int> current = q.front();//Get the current position
        q.pop();//Pop the current position

        for(int i = 0; i < 8; i++)
        {
            int new_r = current.first + moves[i][0];//Get the new row
            int new_c = current.second + moves[i][1];//Get the new column

            if(new_r >= 0 && new_r < 8 && new_c >= 0 && new_c < 8 && board[new_r][new_c] == 0)//Check if the new position is valid
            {
                board[new_r][new_c] = board[current.first][current.second] + 1;//Update the new position
                q.push({new_r, new_c});//Push the new position into the queue
            }
        }
    }

    return board[pawn_r][pawn_c];

}