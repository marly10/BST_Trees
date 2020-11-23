//
// Created by Ricky Marly on 10/25/20.
//

#pragma once
#include "node.h"
#include "array"
#include "string"


class treeNode
{
public:
    treeNode();
    void insertTreeNode(int newAddInt);
    int findTreeNode(int newFindInt);
    void printTreeNode();
    int getTreeHeight();
    int getTreeNodeCount();
    void horizontalNodePrint();

private:
    int findTreeNode(node* otherNode, int newAddInt);
    void insertTreeNode(node* otherNode, int newAddInt);
    void printTreeNode(node* otherNode);
    int getTreeHeight(node* otherNode);
    void horizontalNodePrint(node* otherNode, int maxNodeHeight, string * array);

    //variables being used in the project
    node* root;//ref "same as -head-
    node* otherNode;
    int nodeCountVar = 0;
    int numberCountVar = 0;
    int count = 0;

};