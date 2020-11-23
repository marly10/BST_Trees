//
// Created by Ricky Marly on 10/25/20.
//
#pragma once
#include <iostream>
using namespace std;

class node{
public:
    node();
    node(unsigned int newNumberData);
    int getNumberData();
    void setValue(int newNumberData);
    node* getRight();
    node* getLeft();
    void setLeft(node* newLeftNode);
    void setRight(node* newRightNode);


private:
    unsigned int numberData;
    node *right;
    node *left;
};