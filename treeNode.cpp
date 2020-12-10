//
// Created by Ricky Marly on 10/25/20.
//

#include "treeNode.h"


//basic tree
treeNode::treeNode()
{
    root = nullptr; //always set pointers to null when instantiating
    node *left = nullptr; //always set pointers to null when instantiating
    node *right = nullptr; //always set pointers to null when instantiating
}

//private version treeNode::insert
void treeNode::insertTreeNode(node* newOtherNode, int newAddInt)//public version being used to insert
{
    if(newOtherNode->getNumberData() > newAddInt)//inserting new node to the left BST order
    {
        if(newOtherNode->getLeft() != nullptr)//check if node is null
        {
            insertTreeNode(newOtherNode->getLeft(), newAddInt);//insert value to the left
        }
        else
        {
            newOtherNode->setLeft(new node(newAddInt));//node on left is null ( newAddInt ) new node
        }
    }
    if(newOtherNode->getNumberData() < newAddInt)//inserting new node to the Right BST order
    {
        if(newOtherNode->getRight() != nullptr)//check if node is null
        {
            insertTreeNode(newOtherNode->getRight(), newAddInt);//insert value to the right
        }
        else
        {
            newOtherNode->setRight(new node(newAddInt));//node on right is null ( newAddInt ) new node
        }
    }
}
//public version treeNode::insert
void treeNode::insertTreeNode(int newAddInt)//public version being used to insert
{
    nodeCountVar++;//used to keep count of the number of nodes created

    if(root == nullptr)
    {
        root = new node(newAddInt);//base case
    }
    else
    {
        insertTreeNode(root, newAddInt);
    }
}

int treeNode::getTreeNodeCount()//returns the number of nodes created
{
    return nodeCountVar;
}

//private version treeNode::printTreeNode
void treeNode::printTreeNode(node* newOtherNode)
{
    if(newOtherNode == nullptr)//there are no nodes to print(safety Code)
    {
        return;
    }
    else
    {
        //Create an in-order traversal function and print out each node’s value.
        numberCountVar++;
        printTreeNode(newOtherNode->getRight());
        numberCountVar--;

        //print minuses and leaf value
        for (int i = 0; i < numberCountVar; i++)
        {
            cout << "--";
        }
        cout << newOtherNode->getNumberData() << "\n";

        //Create an in-order traversal function and print out each node’s value.
        numberCountVar++;
        printTreeNode(newOtherNode->getLeft());
        numberCountVar--;
    }
}

//public version treeNode::printTreeNode
void treeNode::printTreeNode()
{
    printTreeNode(root);
}

//private version treeNode::findTreeNode
int treeNode::findTreeNode(node* newOtherNode, int newFindInt)
{
    if(newOtherNode == nullptr)//there are no nodes to print(safery Code)
    {
        return -1;
    }
    if(newOtherNode->getNumberData() == newFindInt)//ensure the node found at the end is printed
    {
        cout << newOtherNode->getNumberData() << " Number found: ";
        return newOtherNode->getNumberData();
    }
    if (newOtherNode->getNumberData() > newFindInt)//the value is located at the left of the tree(root)
    {
        cout << newOtherNode->getNumberData() << " ";//prints space
        return findTreeNode(newOtherNode->getLeft(), newFindInt);//print node
    }
    if (newOtherNode->getNumberData() < newFindInt)//the value is located at the right of the tree(root)
    {
        cout << newOtherNode->getNumberData() << " ";//prints space
        return findTreeNode(newOtherNode->getRight(), newFindInt);//print node
    }
}

//public version treeNode::findTreeNode
int treeNode::findTreeNode(int newFindInt)
{
    return findTreeNode(root, newFindInt);//calls & returns the method with 2 parameters being passed
}

//private version treeNode::getTreeHeight
int treeNode::getTreeHeight(node* newOtherNode)
{
    if(newOtherNode == nullptr)//there are no nodes to print(safery Code)
    {
        return 0;
    }
    else
    {
        int hL = getTreeHeight(newOtherNode->getLeft());//left to int
        int hR = getTreeHeight(newOtherNode->getRight());//right to int

        if (hL > hR)
        {
            return (hL + 1);//returns one more to left tree
        }
        else
        {
            return (hR + 1);//returns one more to right tree
        }

    }
}
//public version treeNode::getTreeHeight
int treeNode::getTreeHeight()
{
    return getTreeHeight(root);
}

//private version treeNode::horizontalNodePrint
void treeNode::horizontalNodePrint(node* newOtherNode, int maxNodeHeight, string * array)
{
    if(newOtherNode == nullptr)//there are no nodes to print(safe Code)
    {
        return;
    }
        count++;
        horizontalNodePrint(newOtherNode->getLeft(), maxNodeHeight, array);//printing on the on left recursion
        for (int i = 0; i < maxNodeHeight; i++)
        {
            if (i == (maxNodeHeight-count))
            {
                if (newOtherNode->getNumberData() < 10)
                {
                    array[i] += " ";
                    array[i] += to_string(newOtherNode->getNumberData());
                }
                else
                {
                    array[i] += to_string(newOtherNode->getNumberData());
                }
            }
            else
            {
                array[i] += "  ";
            }
        }
        horizontalNodePrint(newOtherNode->getRight(), maxNodeHeight, array);//printing on the on right recursion
        count--;
}

//public version treeNode::horizontalNodePrint
void treeNode::horizontalNodePrint()
{
    int maxHeight = getTreeHeight() + 1;//get height
    string * array;
    array = new string[maxHeight];

    horizontalNodePrint(root, maxHeight, array);//recursively call horizontalNodePrint within public version

    for (int i = maxHeight - 1; i > 0; i--)//print array
    {
        cout << array[i] << "\n";
    }
}
