/**
* Title : Binary Search Trees
* Author : Hassan Raza
* ID: 21701811
* Section : 1
* Assignment : 2
* Description : methods for making a BST tree
*/


#include "BST.h"
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include "BSTNode.h"
using namespace std;
//constructor
BST::BST()
{
    root = NULL;
}
//copy constructor
void BST::copyTree(BSTNode *treePtr, BSTNode *& newTreePtr) {
		if (treePtr != NULL) {		// copy node
			newTreePtr = new BSTNode(treePtr->item, NULL, NULL);
			copyTree(treePtr->leftChildPtr, newTreePtr->leftChildPtr);
			copyTree(treePtr->rightChildPtr, newTreePtr->rightChildPtr);
		}
		else
			newTreePtr = NULL;	// copy empty tree
}
BST::BST(const BST& tree)
{
    copyTree(tree.root, root);
}


//destructor
void BST::destroyTree(BSTNode* cur) {

		if (cur != NULL){
			destroyTree(cur->leftChildPtr);
			destroyTree(cur->rightChildPtr);
			delete cur;
			cur = NULL;
		}
}
BST::~BST()
{
    destroyTree(root);
}

//insertion of elements
void BST::insertion(BSTNode *& treePtr, const int& newItem) {

		// Position of insertion found; insert after leaf
		if (treePtr == NULL) {
			treePtr = new BSTNode(newItem, NULL, NULL);
			if (treePtr == NULL)
				cout<<"insertion failed"<<endl;
		}
		// Else search for the insertion position
		else if (newItem < treePtr->item)
			insertion(treePtr->leftChildPtr, newItem);
		else
			insertion(treePtr->rightChildPtr, newItem);
}
void BST::insertItem(int key)
{
    insertion(root, key);
}

//deletion of elements
BSTNode* BST::deletion(BSTNode* main, int key)
{
    if (main == NULL)
        return NULL;
    if (key < main->item)
        main->leftChildPtr = deletion(main->leftChildPtr, key);
    else if (key > main->item)
        main->rightChildPtr = deletion(main->rightChildPtr, key);
    else  //if node found
    {
        if (main->leftChildPtr == NULL)
        {
            BSTNode* temp = main->rightChildPtr;
            free(main);
            return temp;
        }
        else if (main->rightChildPtr == NULL)
        {
            BSTNode* temp = main->leftChildPtr;
            free(main);
            return temp;
        }
        BSTNode* temp = main;
        temp = temp->rightChildPtr;
        while (temp->leftChildPtr != NULL)
            temp = temp->leftChildPtr;
        main->item = temp->item;
        if(temp->rightChildPtr == NULL){
            return main;
        }

        root->rightChildPtr = deletion(root->rightChildPtr, temp->item);
    }
    return main;
}
void BST::deleteItem(int key)
{
    BSTNode *main = root;
    main = deletion(main, key);
}



//retrieving elements
void BST::retrieve(BSTNode *treePtr, int searchKey,
				BSTNode* treeItem)
        {
		if (treePtr == NULL)
			return;
		else if (searchKey == treePtr->item)
			treeItem = treePtr;
		else if (searchKey < treePtr->item)
			retrieve(treePtr->leftChildPtr, searchKey, treeItem);
		else
			retrieve(treePtr->rightChildPtr, searchKey, treeItem);
}
BSTNode* BST::retrieveItem(int key)
{
    BSTNode* cur = NULL;
    retrieve(root, key, cur);
    return cur;
}

//inorder traversal
void BST::inorder(BSTNode *cur, int* pres, int& n)
{
   if (cur != NULL) {
      inorder(cur->leftChildPtr, pres, n);
      pres[n] = cur->item;
      n++;
      inorder(cur->rightChildPtr, pres, n);
   }
}
int* BST::inorderTraversal(int& length)
{
    BSTNode* cur = root;
    int* pres;
    pres = new int[length];
    int n = 0;
    inorder(cur, pres, n);
    return pres;
}

//contains sequence
//if our elements in array is found
bool BST::ifFound(BSTNode *cur, int* seq, int& n, int& i, int& j)
{
    if (cur != NULL) {
        cout<<"we are visiting node: "<<cur->item<<endl;
        ifFound(cur->leftChildPtr,seq,n,i,j);
        if(seq[0]== cur->item)
            n = 1;
        if (i == j)
        {
            n = 0;
            return true;
        }
        if (n == 1)
        {
            if(seq[i] == cur->item)
            {
                i++;
            }
            else
            {
                n = 0;
                return false;
            }
        }
        ifFound(cur->rightChildPtr,seq,n,i,j);
    }
}
//checking for any element of array is present in tree
bool BST::contain(BSTNode* cur, int* seq, int length, bool& res, BSTNode*& found)
{
    if(cur == NULL)
        return false;
    cout<<"we are visiting node: "<<cur->item<<endl;
    //checking for elements
    for(int i = 0; i < length; i++)
    {
        if (seq[i] == cur->item)
        {
            res = true;
            found = cur;
            return res;
        }
    }

    if (res == true)
        return res;
    BSTNode* child;
    child = cur->leftChildPtr;
    //going left
    if(child != NULL){
        if(seq[length-1] <= child->item)
        {
            res = contain(cur->leftChildPtr, seq, length, res, found);
        }
    }

    if (res == true)
        return res;
    //going right
    if(cur->rightChildPtr!=NULL){
        if(seq[0]>=cur->rightChildPtr->item)
        {
            res = contain(cur->rightChildPtr, seq, length, res, found);
        }
    }
    if (res == true)
        return res;

    return res;
}
bool BST::containsSequence(int* seq, int length)
{
    BSTNode* cur = root;
    BSTNode* found = root;
    bool res = false;

    res = contain(cur, seq, length, res, found);

    int n = 0;
    int i = 0;
    int j = length;
    res = ifFound(found, seq, n,i,j);
    if(i == j)
        return true;
    return false;
}



//counting nodes deeper than given value
void BST::pass(BSTNode* cur, int& n, int level, int& i)
{
    n++;

    if (cur != NULL) {
        if (n>level)
            i++;
        pass(cur->leftChildPtr, n, level, i);
        pass(cur->rightChildPtr, n, level, i);
   }
   n--;
}
int BST::countNodesDeeperThan(int level)
{
    BSTNode* cur = root;
    int n = 0;
    int i =0;
    pass(cur, n, level, i);
    return i;
}



//finding maxBalanced Height
int BST::checkTree(BSTNode* cop, int& i)
{
    if(cop != NULL)
    {
    int leftChildHeight =0;
    int rightChildHeight =0;
    //finding height of left tree
    if(cop->leftChildPtr != NULL)
        leftChildHeight = checkTree(cop->leftChildPtr, i);
    if(cop->rightChildPtr != NULL) //finding height of right tree
        rightChildHeight = checkTree(cop->rightChildPtr, i);
    if(cop->leftChildPtr == NULL && cop->rightChildPtr == NULL)
        return 1;
    int heightDifference = leftChildHeight - rightChildHeight; //checking for balanced or not
    //if not balanced making balance
    if(heightDifference > 1)
    {
        int k = 0;
        while (heightDifference > 1)
        {
            heightDifference--;
            i++;
            k++;
        }
        return leftChildHeight-k+1;
    }
    if(heightDifference < -1)
    {
        int k = 0;
        while (heightDifference < -1)
        {
            heightDifference++;
            i++;
            k++;
        }
        return rightChildHeight-k+1;
    }
    return max(leftChildHeight, rightChildHeight) + 1; // Return Height
    }
    else return 0;
}
int BST::maxBalancedHeight()
{
    BSTNode* cop;
    copyTree(root, cop);
    int i = 0;
    int j = checkTree(cop,i);
    return j;
}


