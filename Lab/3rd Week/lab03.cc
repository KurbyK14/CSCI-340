#include <iostream>
#include <list>

/*
lab03 Part 1:

1). Make a linkedlist
2). Then print out the kth to last element of the linkedlist
*/

int kth_to_last(std::list<int> &last, int kth)
{
    auto slow = last.begin();
    auto fast = last.begin();

    for (int i = 0; i < kth + 1; i++)
    {
        if(fast == last.end()) {
            return -1;}
        
        fast++;
    }

    while(fast != last.end())
    {
        slow++;
        fast++;
    }

    return *slow;
}


int main()
{
    int num, kth, element;
    std::cout << "Enter the number of elements in the list: " << std::endl;
    std::cin >> num;

    if(num < 1)
    {
        std::cout << "The list must have at least one element." << std::endl;
        return 0;
    }

    std::list<int> last;
    std::cout << "Enter the elements of the list: " << std::endl;

    for (int i = 0; i < num; i++)
    {
        std::cin >> element;
        last.push_back(element);
    }

    std::cout << "Enter the value for the kth element from the last element, you want to see: "<< std::endl;
    std::cin >> kth;

    if(kth < 1)
    {
        std::cout << "The kth element must be a positive integer." << std::endl;
        return 0;
    }

    int result = kth_to_last(last, kth);

    if (result == -1)
    {
        std::cout << "The list does not have " << kth << " elements." << std::endl;
    }
    else
    {
        std::cout << "The kth element from the last element is: " << result << std::endl;
    }
}
