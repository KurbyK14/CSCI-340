#include <iostream>
#include <map>

int histogram(int a[], int len)
{
    if(len < 0 || a == NULL)//if the array is empty or the length is negative
    {
        return 0;
    }

    std::map<int, int> map;//create a map to store the frequency of each number
                           //the key is the number and the value is the frequency

    for(int i = 0; i < len; i++)//loop through the array
    {
        if(map.find(a[i]) == map.end())//if the number is not in the map
        {
            map[a[i]] = 1;//add it to the map with a frequency of 1
        }
        else//if the number is in the map
        {
            map[a[i]]++;//increment the frequency
        }
    }

    for(int i = 0; i < len; i++)//loop through the array
    {
        if(map.find(a[i]) != map.end())
        {
            std::cout << a[i] << " occurs " << map[a[i]] << " time(s)." << std::endl;//print the number and its frequency
            map.erase(a[i]);//prevents the value from being printed twice
        }
    }

    return 1;
}