#include <iostream>
#include <algorithm>
#include <map>
#include <string>

 std::string decimal_to_roman(int decimal_value)
{
    std::string roman_val;//Create a string to hold the roman numeral value to return
    std::map<int, std::string, std::greater<int>> roman_num = {//Create a map of most common roman numerals
    {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
    {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
    {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"},
    {1, "I"}};
    
    for (auto it = roman_num.begin(); it != roman_num.end(); it++)
    {
        int key = it->first;//Get the key value
        std::string val = it->second;//Get the roman numeral value

        while (decimal_value >= key)//While the decimal value is greater than the key value
        {
            decimal_value -= key;//Subtract the key value from the decimal value
            roman_val += val;//Add the roman numeral value to the string to return ;
        }
    }
    return roman_val;
}