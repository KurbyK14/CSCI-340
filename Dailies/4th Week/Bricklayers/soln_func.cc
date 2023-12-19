#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

int bricklayers(int b, int a[], int len)
{
    if(b <= 0 || len <= 0)//checks if the number of bricklayers or the number of bricks is less than or equal to 0
    {
        return -1;
    }

    for(int i = 0; i < len; i++)//checks if any of the bricks are less than or equal to 0
    {
        if(a[i] <= 0)
        {
            return -1;
        }
    }

    std::vector<int> a_vec(len);//creates a vector of the array a
    for(int i = 0; i < len; i++)
    {
        a_vec[i] = a[i];//copies the array a into the vector a_vec
    }
    
    std::vector<int> b_time(b, 0);//creates a vector of bricklayers size b and initializes all elements or their times to 0

    sort(a_vec.begin(), a_vec.end());//greater<int>() is a function object that sorts the array in descending order

    int total_time = 0;
    for(int i = 0; i < len; i+=b)
    {
        int group_max = 0;

        for(int j = 0; j < b; j++)
        {
            if(i+j < len)
            {
                if(a_vec[i+j] > group_max)
                {
                    group_max = a_vec[i+j];
                }
            }
        }
        total_time += group_max;
    }

    
    return total_time;//returns the maximum time of the bricklayers

}