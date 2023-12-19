#include <iostream>
#include <vector>
#include <algorithm>

bool pentalpha2(std::vector<int> &board, int depth, int last_pos);//the recursive function

bool pentalpha(int place_order[])
{
    const int board_size = 25;//the size of the board
    std::vector<int> board(board_size, -1);//create a vector to store the board; -1 means we're outside the board
                                      //so this a board initialized with -1's
    board[place_order[0]] = 0;//place the first piece on the board

    if(pentalpha2(board, 1, place_order[0]))//if the board is solvable
    {
        for(int i = 1; i < 9; i++)
        {
            place_order[i] = std::find(board.begin(), board.end(), i) - board.begin();//place the rest of the pieces on the board
        }
    }
    else//if the board is not solvable
    {
        return false;
    }
    return true;
}

bool pentalpha2(std::vector<int> &board, int depth, int last_pos)
{
    const int max_num = 9;//the maximum number of pieces
    int traverse[max_num][2] = {{2, 0},{1,1},{-1,1},{-2,0},{-1,-1},{1,-1},{0,2},{0,-2},{0,0}};
            //The moves that can be made represented in a 2D array; the first # is the row and the second # is the column
            //{2, 0} move down 2 positions
            //{1,1} move down 1 position and right 1 position
            //{-1,1} move up 1 position and right 1 position
            //{-2,0} move up 2 positions
            //{-1,-1} move up 1 position and left 1 position
            //{1,-1} move down 1 position and left 1 position
            //{0,2} move right 2 positions
            //{0,-2} move left 2 positions
            //{0,0} stay in the same position

    if(depth == max_num)//if we've placed all the pieces
    {
        return true;
    }

    for(int i = 0; i < max_num; i++)//loop through the moves
    {
        int x = last_pos / 10 + traverse[i][0];//get the row of the last position
        int y = last_pos % 10 + traverse[i][1];//get the column of the last position
        int new_pos = x * 10 + y;//get the new position

        if(x < 0 || x > 4 || y < 0 || y > 4 || board[new_pos] != -1)//if the new position is outside the board
        {
            continue;//outside the board or the position is already occupied
        }

        board[new_pos] = depth;//place the piece on the board
        if(pentalpha2(board, depth + 1, new_pos))//if the board is solvable
        {
            return true;
        }
        board[new_pos] = -1;//remove the piece from the board
    }

    return false;
}