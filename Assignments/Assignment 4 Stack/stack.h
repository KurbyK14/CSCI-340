#ifndef STACK_H
#define STACK_H

/* 	Jacob Kurbis (Z1945650)
	CSCI 340: Data Structures Section: 0003
	Assignment 4	Due: 02/20/2023
	
	I certify that this is my own work and where appropriate an extension 
	of the starter code provided for the assignment.
*/

#include <queue>
#include <stdexcept>

template<typename T>
class Stack
{
private:
    std::queue<T> q1;	// These queues are where the stack's elements 
    std::queue<T> q2;	// are to be saved.

public:
    bool empty() const;
    int size() const;
    const T& top();
    void push(const T &val);
    void pop();
};


// Note that the members of a template go into a .h file since 
// they are not compiled directly into a .o file like the members 
// of regular/non-template classes.




// Place your Stack class member implementations here.
/**
 * @brief: Checks if the stack is empty
 * 
 * @return: Returns true if the stack is empty, false otherwise
 */
template<typename T> 
bool Stack<T>::empty() const
{
    return q1.empty();
}

/**
 * @brief: Returns the size of the stack 
 * 
 * @return: Returns the size of the stack
 */
template<typename T>
int Stack<T>::size() const
{
    return q1.size();
}

/**
 * @brief: Returns a reference to the top element of the stack
 * 
 * @return: a reference to the top element of the stack
 */
template<typename T>
const T& Stack<T>::top()
{   
    if(q1.empty())
    {
        throw std::out_of_range("stack is empty");//Throws an exception if the stack is empty
    }
    return q1.front();
}

/**
 * @brief: Pushes a value onto the stack
 * 
 * @param val: the value to be pushed onto the stack 
 */
template<typename T>
void Stack<T>::push(const T &val)
{
    q2.push(val);//Pushes the value onto the stack

    while (!q1.empty())//Pushes all the elements from q1 to q2
    {
        q2.push(q1.front());
        q1.pop();
    }

    //Swap the names of two queues
    std::queue<T> q = q1;
                  q1 = q2;
                  q2 = q;
}

/**
 * @brief: Pops the top element off the stack
 */
template<typename T>
void Stack<T>::pop()
{

    if(q1.empty())
    {
        throw std::out_of_range("stack is empty");//Throws an exception if the stack is empty
    }
    q1.pop();//Pops the top element off the stack

}

#endif // STACK_H
