#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

/*  Jacob Kurbis (Z1945650)
	CSCI 340: Data Structures Section: 0003
	Assignment 9	Due: 04/05/2023
	
	I certify that this is my own work and where appropriate an extension 
	of the starter code provided for the assignment.
*/

#include "btree.h"

template <typename T>
class BinarySearchTree : public BinaryTree<T>
{
public:
    void Insert(const T &x);       // inserts node with value x
    bool Search(const T &x) const; // searches leaf with value x
    bool Remove(const T &x);       // removes leaf with value x
private:
    void _Insert(Node<T> *&, const T &);      // private version of insert
    bool _Search(Node<T> *, const T &) const; // private version of search
    void _Remove(Node<T> *&, const T &);      // private version of remove
    bool _Leaf(Node<T> *node) const;          // checks if node is leaf
};


/**
 * @brief: inserts a node with value x into the tree
 *
 * @param x: value to be inserted
 *
 */
template <typename T>
void BinarySearchTree<T>::Insert(const T &x)
{
    _Insert(this->root, x);
}


/**
 * @brief: searches for a leaf with value x
 *
 * @param x: value to be searched for
 *
 * @return: true if leaf is found, false otherwise
 *
 */
template <typename T>
bool BinarySearchTree<T>::Search(const T &x) const
{
    return _Search(this->root, x);
}


/**
 * @brief: removes a leaf with value x from the tree
 *
 * @param x: value to be removed
 *
 * @return: true if leaf is removed, false otherwise
 *
 */
template <typename T>
bool BinarySearchTree<T>::Remove(const T &x)
{
    if(Search(x))//if leaf is found
    {
        _Remove(this->root, x);//remove leaf
        return true;
    }
    else
    {
        return false;//leaf not found
    }
}


/**
 * @brief: inserts a node with value x into the tree
 *
 * @param node: node to be inserted
 *
 */
template <typename T>
void BinarySearchTree<T>::_Insert(Node<T> *&node, const T &x)
{
    if (node == nullptr)//if node is null
    {
        node = new Node<T>(x);
    }

    //Recursively traverse tree
    if (x < node->data)//insert into left subtree
    {
        _Insert(node->left, x);
    }
    else if (x > node->data)//insert into right subtree
    {
        _Insert(node->right, x);
    }
}


/**
 * @brief: searches for a leaf with value x
 *
 * @param node: node to be searched
 *
 * @param x: value to be searched for
 *
 * @return: true if leaf is found, false otherwise
 *
 */
template <typename T>
bool BinarySearchTree<T>::_Search(Node<T> *node, const T &x) const
{
    if (node == nullptr)//if node is null
    {
        return false;
    }

    //If node is a leaf return true; otherwise return false
    if(x == node->data)
    {
        if(_Leaf(node))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    //Recursively traverse tree
    else if (x < node->data)
    {
        return _Search(node->left, x);//search left subtree
    }
    else if (x > node->data)
    {
        return _Search(node->right, x);//search right subtree
    }

    return false;
}


/**
 * @brief: removes a leaf with value x from the tree
 *
 * @param node: node to be removed
 *
 * @param x: value to be removed
 *
 */
template <typename T>
void BinarySearchTree<T>::_Remove(Node<T> *&node, const T &x)
{
    if (node == nullptr)//if node is null
    {
        return;
    }

    //Recursively traverse tree
    if (x < node->data)
    {
        _Remove(node->left, x);//remove from left subtree
    }
    else if (x > node->data)
    {
        _Remove(node->right, x);//remove from right subtree
    }
    else
    {
        if(_Leaf(node))//if node is a leaf
        {
            delete node;
            node = nullptr;
        }
        else if(node->left == nullptr)//if node has one child on left
        {
            Node<T> *temp = node;
            node = node->right;
            delete temp;
        }
        else if(node->right == nullptr)//if node has one child on right
        {
            Node<T> *temp = node;
            node = node->left;
            delete temp;
        }
        else
        {
            Node<T> *temp = node->right;//if node has two children
            while(temp->left != nullptr)//find smallest value in right subtree
            {
                temp = temp->left;
            }
            node->data = temp->data;//replace node with smallest value
            _Remove(node->right, temp->data);//remove smallest value
        }
    }

}


/**
 * @brief: checks if node is a leaf
 *
 * @param node: node to be checked
 *
 * @return: true if node is a leaf, false otherwise
 *
 */
template <typename T>
bool BinarySearchTree<T>::_Leaf(Node<T> *node) const
{
    return (node->left == nullptr && node->right == nullptr);//return true if node is a leaf
}

#endif // End of BINARYSEARCHTREE_H_