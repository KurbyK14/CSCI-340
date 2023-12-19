#include <iostream>
#include <vector>
#include <algorithm>

int howmuchwater(unsigned int a[], int n)
{
    if(n <= 0 || a == NULL)//If the array is empty or the size is 0
    {
        return -1;
    }

    int water = 0;//Total amount of water that can be stored
    std::vector<unsigned int> max_L(n);//Max height of the left side of the array
    std::vector<unsigned int> max_R(n);//Max height of the right side of the array

    max_L[0] = a[0];//The first element of the array is the max water level of the left side
    for(int i = 1; i < n; i++)
    {
        max_L[i] = std::max(max_L[i-1], a[i]);//std::max returns the max of the two values
        
    }

    max_R[n-1] = a[n-1];//The last element of the array is the max water level of the right side
    for(int i = n-2; i >= 0; i--)
    {
        max_R[i] = std::max(max_R[i+1], a[i]);//std::max returns the max of the two values
        
    }

    //The amount of water that can be stored at each index
    for(int i = 0; i < n; i++)
    {
        water += std::min(max_L[i], max_R[i]) - a[i];
    }

    return water;
}