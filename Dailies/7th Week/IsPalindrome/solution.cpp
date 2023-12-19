#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

bool ispalindrome(const std::string& s)
{
    std::string palindrome;//Create a new string to hold the palindrome

    //Loop through the string and add only alphanumeric characters to the palindrome string
    for (unsigned i = 0; i < s.size(); i++)
    {
        char p = s[i];
        if(isalnum(p))
        {
            palindrome += tolower(p);//Convert to lowercase
        }
    }

    std::string r_palindrome = palindrome;//Create a new string to hold the reversed palindrome
    std::reverse(palindrome.begin(), palindrome.end());//Reverse the palindrome

    return std::equal(palindrome.begin(), palindrome.end(), r_palindrome.begin());//Compare the two strings

}