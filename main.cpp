#include <iostream>
#include "treeNode.h"

int main() {
    treeNode theTree = treeNode();    //insert test nodes
    theTree.insertTreeNode(8);
    theTree.insertTreeNode(4);
    theTree.insertTreeNode(12);
    theTree.insertTreeNode(2);
    theTree.insertTreeNode(6);
    theTree.insertTreeNode(10);
    theTree.insertTreeNode(14);
    theTree.insertTreeNode(1);
    theTree.insertTreeNode(9);
    theTree.insertTreeNode(11);


    cout << theTree.findTreeNode(4) << "\n";
    cout << theTree.findTreeNode(5) << "\n";
    cout << theTree.findTreeNode(6) << "\n";
    cout << theTree.findTreeNode(10) << "\n";
    cout << theTree.findTreeNode(9) << "\n";

    theTree.printTreeNode();//prints node --

    theTree.horizontalNodePrint();//prints tree --


}
