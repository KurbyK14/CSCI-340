#include<iostream>
#include<vector>
#include<algorithm>

using std::cout;
using std::vector;
using std::endl;

/*************************************************************************************************************************
 Purpose: Gain experience with STL vectors ....
 
 Task: Complete the following steps.
 
 1) add 10 natural numbers which are multiples of 10 eg: 10,20,....100.
 2) Print the vector.
 3) add 5 to each elements of the vector.
 4) print vector again in reverse order using a reverse iterator
 5) modify vector again by adding a random number between 0 and 99 to each element
 6) print vector again
 7) using STL sort the vector using mySortFunction for comparison
 8) print the vector again adding ""(" << *i%8 << ")"" to show how items are sorted, i is an iterator
 ***************************************************************************************************************************/

bool mySortFunction(int i,int j) {return ((i%8) > (j%8));}

int main()
{
    vector<int> myvector;
    
    // (1) add 10 natural numbers which are multiples of 10 eg: 10,20,....100
    for(int i = 1; i <= 10; i++)
    {
        myvector.push_back(i*10);
    }
    
    // (2) display the vector
    std::cout << "Vector: ";
    for(auto it = myvector.begin(); it != myvector.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl << std::endl;
    
    // (3) Add number 5 to all the elements
    for(auto& i : myvector)
    {
        i += 5;
    }
    
    // (4) display the vector using reverse iterator
    std::cout << "Vector in reverse order and after adding '5' to each element: ";
    for(auto it = myvector.rbegin(); it != myvector.rend(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl << std::endl;
    
    // (5) Add random number between 0 and 99 to all elements (you will need rand() % 100)
    for(auto& i : myvector)
    {
        i += rand() % 100;
    }
    
    // (6) display the vector
    std::cout << "Vector after adding random numbers: ";
    for(auto it = myvector.begin(); it != myvector.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl << std::endl;
    
    // (7) sort the array based on mySortFunction
    sort(myvector.begin(), myvector.end(), mySortFunction);
    
    // (8) display vector again, change cout to include parens with mod to show how items are sorted
    // the new code would look something like ""(" << *i%8 << ")"" where i is an iterator
    std::cout << "Vector after sorting: " << std::endl;
    for(auto it = myvector.begin(); it != myvector.end(); it++)
    {
        std::cout << "With mod --> (" << *it%8 << ") of item --> " << *it << std::endl;
    }
    std::cout << std::endl << std::endl;
    
    return 0;
}
