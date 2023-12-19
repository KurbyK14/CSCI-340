#include <iostream>
#include <string>

using namespace std;

//lab04
//make a binary search tree
//then print out the Nth element of the tree

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int data)
{
    Node* node = new Node;

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

Node* insert(Node* node, int data)
{
    if(node == NULL)
    {
        return newNode(data);
    }

    if(data < node->data)
    {
        node->left = insert(node->left, data);
    }
    else if(data > node->data)
    {
        node->right = insert(node->right, data);
    }

    return node;
}

void findNth(Node* node, int& n, int& result)
{
    if(node == NULL || n == 0)
    {
        return;
    }

    findNth(node->left, n, result);
    n--;

    if(n == 0)
    {
        result = node->data;
    }

    findNth(node->right, n, result);
}

void printTree(Node* node, string prefix = "", bool isLeft = true)
{
    if (node == NULL)
    {
        return;
    }

    std::cout << prefix;
    std::cout << (isLeft ? "├──" : "└──");
    std::cout << node->data << std::endl;

    // Recursively print the left and right subtrees
    printTree(node->left, prefix + (isLeft ? "│   " : "    "), true);
    printTree(node->right, prefix + (isLeft ? "│   " : "    "), false);
}

int main()
{
    Node* root = NULL;
    int num;

    std::cout << "How many elements do you want to insert into the binary search tree?: " << std::endl;
    std::cin >> num;
    std::cout << std::endl;

    if(num < 1)
    {
        std::cout << "The tree must have at least one element." << std::endl;
        return 0;
    }


    std::cout << "Enter " << num << " elements:" << std::endl;
    for(int i = 0; i < num; i++)
    {
        int val;
        std::cin >> val;
        root = insert(root, val);
    }
    std::cout << std::endl;

    std::cout << "The tree is: " << std::endl;
    printTree(root);
    std::cout << std::endl << std::endl;

    int nth;
    std::cout << "Enter the Nth element you want to see: " << std::endl;
    std::cin >> nth;

    int result = -1;
    findNth(root, nth, result);

    if(result != -1)
    {
        std::cout << "The Nth element you chose in the tree is " << result << std::endl;
    }
    else
    {
        std::cout << "Invalid Input" << std::endl;  
    }

    return 0;
}