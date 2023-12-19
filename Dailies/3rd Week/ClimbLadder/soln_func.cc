#include <iostream>
#include <vector>

int nclimbs(int n)
{
    //If the number of rungs is less than or equal to 0,
    //equal to 1, or equal to 2
    if(n <= 0) {return -1;}
    else if(n == 1) {return 1;}
    else if(n == 2) {return 2;}

    //If the number of rungs is greater than 2
    //Create a vector to store the number of ways to climb
    std::vector<int> rungs(n+1);

    rungs[0] = 1;//One way to climb 1 rung
    rungs[1] = 2;//Two ways to climb 2 rungs
    rungs[2] = 4;//Four ways to climb 3 rungs

    //For loop to calculate the number of ways to climb
    //the rungs
    for(int i = 3; i <= n; i++)//Start at 3; end at n; increment by 1
    {
        rungs[i] = rungs[i-1] + rungs[i-2] + rungs[i-3];
    }

    //Return the number of ways to climb the rungs
    return rungs[n-1];
    
    
}
