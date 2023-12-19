#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>

int count_hex_a(int n)
{
    if(n < 0)
    {
        return -1;//When the integer is less than 0
    }

    std::stringstream hex;//Create a stringstream object
    hex << std::hex << n;//Convert 'n' into a hexadecimal format

    std::string hex_to_string = hex.str();//Convert 'n' into a hexadecimal string
    int cnt = std::count(hex_to_string.begin(), hex_to_string.end(), 'a');//count the ocuurences of 'a'

    return cnt;//Return the number of 'a' in the hexadecimal string

}