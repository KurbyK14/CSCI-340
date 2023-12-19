#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

int mintokens(int c, int a[], int len)
{
    if(c < 1 || len < 1 || a == NULL)//Error checking
    {
        return -1;
    }


    std::vector<int> v(c + 1, INT_MAX);//Create a vector of size c + 1 and fill it with INT_MAX

    v[0] = 0;//Set the first element to 0

    for(int i = 0; i < len; i++)//Loop through the coins
    {
        for(int j = a[i]; j <= c; j++)//Loop through the vector
        {
            if(v[j - a[i]] != INT_MAX)//If the previous element is not INT_MAX
            {
                v[j] = std::min(v[j], v[j - a[i]] + 1);//Set the current element to the minimum of the current element and the previous element + 1
            }
        }
    }

    if(v[c] == INT_MAX)//If the last element is still INT_MAX
    {
        return -1;
    }

    return v[c];//Return the last element

}
