/**
* Title : Binary Search Trees
* Author : Hassan Raza
* ID: 21701811
* Section : 1
* Assignment : 2
* Description : header file for BST  which is used for making a BST tree
*/



#ifndef BST_H
#define BST_H
#include <iostream>
#include "BSTNode.h"
using namespace std;

class BST
{
    public:
        BST();
        BST(const BST& tree);
        void copyTree(BSTNode *treePtr, BSTNode *& newTreePtr);
        ~BST();
        void destroyTree(BSTNode* cur);
        void insertItem(int key); // 5 points
        void deleteItem(int key); // 5 points
        BSTNode* retrieveItem(int key); // 5 points
        int* inorderTraversal(int& length);
        void retrieve(BSTNode *treePtr, int searchKey,BSTNode* treeItem);
        void insertion(BSTNode *& treePtr, const int& newItem);
        BSTNode* deletion(BSTNode* main, int key);
        void inorder(BSTNode *cur, int* pres, int& n);

        bool containsSequence(int* seq, int length);
        bool contain(BSTNode* cur, int* seq, int length, bool& res, BSTNode*& found);
        bool ifFound(BSTNode *cur, int* seq, int& n, int& i, int& j);

        int countNodesDeeperThan(int level);
        void pass(BSTNode* cur, int& n, int level, int& i);

        int maxBalancedHeight();
        int checkTree(BSTNode* cop, int& i);

    private:
        BSTNode *root;
};

#endif // BST_H
