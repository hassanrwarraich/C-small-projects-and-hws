/**
* Title : Binary Search Trees
* Author : Hassan Raza
* ID: 21701811
* Section : 1
* Assignment : 2
* Description : header file for BSTNode
*/


#ifndef BSTNODE_H
#define BSTNODE_H
#include <iostream>
using namespace std;

class BSTNode
{
    public:




    private:
        BSTNode();
		BSTNode(const int& nodeItem,BSTNode *left = NULL,
							     BSTNode *right = NULL);



        int item; 		// a data item in the tree
		BSTNode *leftChildPtr;	// pointers to children
		BSTNode *rightChildPtr;

    friend class BST;

};

#endif // BSTNODE_H
