/**
* Title : Binary Search Trees
* Author : Hassan Raza
* ID: 21701811
* Section : 1
* Assignment : 2
* Description : methods making a node in tree
*/


#include "BSTNode.h"
#include <iostream>
using namespace std;
//constructor
BSTNode::BSTNode()
{
    item = 0;
    leftChildPtr = NULL;
    rightChildPtr = NULL;
}
//copy constructor
BSTNode::BSTNode(const int& nodeItem,BSTNode *left, BSTNode *right): item(nodeItem), leftChildPtr(left), rightChildPtr(right)
{

}
