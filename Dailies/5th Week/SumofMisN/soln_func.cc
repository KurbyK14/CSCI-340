#include <iostream>
#include <algorithm>
#include <vector>

int sumisn(int a[], int len, int m, int n)
{
    if(len < m)
    {
        return 0;
    }

    int cnt = 0, sum = 0;
    std::vector<bool> temp_arr(len, false);//temp vector to mark visited elements

    //Loop through array
    for(int i = 0; i < len; i++)
    {
        if(temp_arr[i])//if visited, skip
        {
            continue;
        }

        temp_arr[i] = true;//mark as visited
        cnt++;//increment count
        sum += a[i];//set sum to current element

        if(cnt == m)//if count is equal to m
        {
            if(sum == n)//if sum is equal to n
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        //Continue to next element
        for(int j = i + 1; j < len; j++)
        {
            if(temp_arr[j])//if visited, skip
            {
                continue;
            }

            temp_arr[j] = true;//mark as visited
            cnt++;//increment count
            sum += a[j];//add current element to sum

            if(cnt == m)
            {
                if(sum == n)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            
        }

    }

    return 0;//If all else fails, return 0
}