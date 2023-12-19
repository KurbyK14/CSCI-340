#ifndef H_BTREE
#define H_BTREE

/*  Jacob Kurbis (Z1945650)
	CSCI 340: Data Structures Section: 0003
	Assignment 9	Due: 04/05/2023
	
	I certify that this is my own work and where appropriate an extension 
	of the starter code provided for the assignment.
*/

#include "node.h"
#include <math.h>


template <typename T> class BinaryTree{

public:
    BinaryTree();                                      // default constructor
    unsigned     getSize() const;                      // returns size of tree
    unsigned     getHeight() const;                    // returns height of tree
    virtual void Insert(const T&);                     // inserts node in tree
    void         Inorder(void (*)(const T&));          // inorder traversal of tree

protected:
    Node<T> *root;                                      // root of tree

private:
    unsigned _getSize(Node<T> *) const;                 // private version of getSize()
    unsigned _getHeight(Node<T> *) const;               // private version of getHeight()
    void     _Insert(Node<T> *&, const T&);             // private version of Insert()
    void     _Inorder(Node<T> *, void (*)(const T&));   // private version of Inorder()
};

typedef enum {left_side, right_side } SIDE;// Enum for left and right side

/**
 * @brief: Randomly chooses a side to insert a node
 * 
 * @return SIDE: Returns a random side
 *
 */
SIDE rnd()
{ 
    return rand()%2 ? right_side : left_side;// Return a random side
}// End of rnd()


/**
 * @brief: default constructor for BinaryTree
 * 
 */
template <typename T>
BinaryTree<T>::BinaryTree()
{
    root = nullptr;// Set root to nullptr
}


/**
 * @brief: Gets the size of the tree
 *
 * @return unsigned: Returns the size of the tree
 *
 */
template <typename T>
unsigned BinaryTree<T>::getSize() const
{
    return _getSize(root);// Call private version of getSize()
}


/**
 * @brief: Gets the height of the tree
 *
 * @return unsigned: Returns the height of the tree
 *
 */
template <typename T>
unsigned BinaryTree<T>::getHeight() const
{
    return _getHeight(root);// Call private version of getHeight()
}


/**
 * @brief: Inserts a node into the tree
 *
 * @param x: The value to be inserted
 *
 */
template <typename T>
void BinaryTree<T>::Insert(const T& x)
{
    _Insert(root, x);// Call private version of Insert()
}


/**
 * @brief: Sorts the tree inorder
 *
 * @param visitNode: The function to be called on each node
 * 
 */
template <typename T>
void BinaryTree<T>::Inorder(void (*visitNode)(const T&))
{
    _Inorder(root, visitNode);// Call private version of Inorder()
}


/**
 * @brief: Determines the size of the tree
 *
 * @param node: The node to be checked
 * 
 * @return unsigned: Returns the size of the tree
 */
template <typename T>
unsigned BinaryTree<T>::_getSize(Node<T> *node) const
{
    if(node == nullptr)
    {
        return 0;// If node is nullptr, return 0
    }
    else
    {
        return 1 + _getSize(node->left) + _getSize(node->right);// Return 1 + size of left side + size of right side
    }
}


/**
 * @brief: Determines the height of the tree
 *
 * @param node: The node to be checked
 * 
 * @return unsigned: Returns the height of the tree
 */
template <typename T>
unsigned BinaryTree<T>::_getHeight(Node<T> *node) const
{
    if(node == nullptr)
    {
        return 0;// If node is nullptr, return 0
    }
    else
    {
        unsigned leftHeight = _getHeight(node->left);// Get height of left side
        unsigned rightHeight = _getHeight(node->right);// Get height of right side

        if(leftHeight > rightHeight)
        {
            return 1 + leftHeight;// Return 1 + height of left side
        }
        else
        {
            return 1 + rightHeight;// Return 1 + height of right side
        }
    }
}


/**
 * @brief: Inserts a node into the tree
 *
 * @param node: The node to be inserted
 * @param x: The value to be inserted
 * 
 */
template <typename T>
void BinaryTree<T>::_Insert(Node<T>*& node, const T& x)
{
    if(node == nullptr)
    {
        node = new Node<T>(x);//If root node is nullptr, set root node to new node
    }
    else
    {
        bool inserted = false;//Bool to determine if node has been inserted
        Node<T> *currentNode = node;//Set currentNode to root node

        while(!inserted)
        {
            SIDE rnd_side = rnd();//Get random side

            if(rnd_side == left_side)
            {
                if(currentNode->left == nullptr)
                {
                    currentNode->left = new Node<T>(x);//If left side is nullptr, set left side to new node
                    inserted = true;//Set inserted to true
                }
                else
                {
                    currentNode = currentNode->left;//Set currentNode to left side
                }
            }
            else
            {
                if(currentNode->right == nullptr)
                {
                    currentNode->right = new Node<T>(x);//If right side is nullptr, set right side to new node
                    inserted = true;//Set inserted to true
                }
                else
                {
                    currentNode = currentNode->right;//Set currentNode to right side
                }
            }
        }
    }
}


/**
 * @brief: Sorts the tree inorder
 *
 * @param node: The node to be sorted
 * @param visitNode: The function to be called on each node
 * 
 */
template <typename T>
void BinaryTree<T>::_Inorder(Node<T> *node, void (*visitNode)(const T&))
{
    if(node != nullptr)//If node is not nullptr
    {
        _Inorder(node->left, visitNode);//Sort left side
        visitNode(node->data);//Visit node
        _Inorder(node->right, visitNode);//Sort right side
    }
}

#endif // End of H_BTREE