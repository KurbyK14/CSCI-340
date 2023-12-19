#include <unordered_map>
#include <iostream>
#include <string>

int main()
{
    char buffer;

    std::cin >> std::noskipws;

    std::unordered_map<char, std::string> htmlMap = 
    {
        {'&', "&amp;"}, 
        {'<', "&lt;"},
        {'>', "&gt;"},
        {'"', "&quot;"},
        {'\'', "&apos;"}
    };

    while (std::cin >> buffer)
    {
        auto it = htmlMap.find(buffer);

        if(it != htmlMap.end())
        {
            std::cout << it -> second;
        }
        else
        {
            std::cout << buffer;
        }
    }

    return 0;
}