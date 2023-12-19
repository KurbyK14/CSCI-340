#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

//Implement a function that takes a string and checks if there are any repeating characters in it.

//Function prototype(s)
bool duplicateCharacters(std::string& str);

int main() 
{
    std::string str = "Hello World";
    std::string str2 = "Snake";
    std::string str3 = "Aardvark";
    std::string str4 = "Elephant";
    std::string str5 = "Zebra";

    std::cout << duplicateCharacters(str) << std::endl;
    std::cout << duplicateCharacters(str2) << std::endl;
    std::cout << duplicateCharacters(str3) << std::endl;
    std::cout << duplicateCharacters(str4) << std::endl;
    std::cout << duplicateCharacters(str5) << std::endl;

    return 0;
}

bool duplicateCharacters(std::string& str) 
{
    std::vector<char> charVector;

    for (unsigned int i = 0; i < str.length(); i++)
    {
        char c = std::tolower(str[i]);
        charVector.push_back(c);

    }

    std::sort(charVector.begin(), charVector.end());

    for (unsigned int i = 0; i < charVector.size() - 1; i++) 
    {
        if (charVector[i] == charVector[i + 1]) 
        {
            std::cout << "This string has duplicate characters --> ";
            return true;
            std:: cout << std::endl;
        }
    }

    std::cout << "This string does not have duplicate characters --> ";
    return false;
}