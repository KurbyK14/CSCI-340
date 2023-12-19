#include "TreeNode.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

bool secondsmallest(TreeNode *root, int &val)
{

    if(!root || (!root->left && !root->right))//If the tree is empty or only has one node
    {
        return false;
    }

    std::stack<TreeNode*> s;//Stack to store the nodes
    std::vector<int> v;//Vector to store the values of the tree
    TreeNode *current = root;//Current node

    while(current != NULL || !s.empty())//While the stack is not empty
    {
        while(current != NULL)//While the current node is not null
        {
            s.push(current);//Push the current node onto the stack
            current = current->left;//Set the current node to the left child
        }

        current = s.top();//Set the current node to the top of the stack
        s.pop();//Pop the top of the stack
        v.push_back(current->value);//Push the value of the current node onto the vector
        current = current->right;//Set the current node to the right child
    }

    std::sort(v.begin(), v.end());//Sort the vector
    val = v[1];//Return the second smallest value
    return true;
    
}