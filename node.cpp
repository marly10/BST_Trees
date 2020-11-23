//
// Created by Ricky Marly on 10/25/20.
//

#include "node.h"

node::node()//empty constructor with variables initialited to default
{
    numberData = 0;
    node* left;
    node* right;
}

node::node(unsigned int newNumberData)//constructor with @1 parameter
{
    this->numberData = newNumberData;
    this->left = nullptr;//null pointer
    this->right = nullptr;//null pointer
}

//different setters utilized
void node::setValue(int newNumberData)//setter of int
{
    numberData = newNumberData;
}
node* node::getRight()//getter of right node
{
    return right;
}

node* node::getLeft()//getter of left node
{
    return left;
}
void node::setLeft(node* newLeftNode)
{
    left = newLeftNode;
}
void node::setRight(node* newRightNode)
{
    right = newRightNode;
}

//different getters utilized Tree node written in C++. Demonstrating the use & implementation of nodes using BST principles.
int node::getNumberData()//getter
{
    return numberData;
}

