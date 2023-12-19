#include <iostream>
#include <algorithm>
#include <vector>

int mintimesteps(int a[], int len, int n)
{
    std::vector<int> v(a, a + len);//copy the array to a vector
    int num_TM = 0;//min number of time machines
    int current_TM = 0;//current time machine can reach

    while(current_TM < n)//while current time machine can't reach the end
    {
        if(num_TM == len)
        {
            break;
        }

        auto it = std::find_if(v.begin(), v.end(), [current_TM](int x){return x > current_TM;});
        //find the first time machine can reach the current time machine

        current_TM = *(std::max_element(v.begin(), it)) + current_TM;//update the current time machine can reach
        num_TM++;//update the min number of time machines
        
    }

    if(current_TM < n)
    {
        return -1;//if the current time machine can't reach any further, return -1
    }

    return num_TM;//return the min number of time machines
}