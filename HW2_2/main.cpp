/**
* Title : Binary Search Trees
* Author : Hassan Raza
* ID: 21701811
* Section : 1
* Assignment : 2
* Description : main method which creates a BST and implement different methods on it
*/


#include "BST.h"
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include "BSTNode.h"
using namespace std;
int  main()
{
    BST bst;
    bst.insertItem(8);
    bst.insertItem(4);
    bst.insertItem(13);
    bst.insertItem(3);
    bst.insertItem(6);
    bst.insertItem(12);
    bst.insertItem(15);
    bst.insertItem(1);
    bst.insertItem(5);
    bst.insertItem(10);
    bst.insertItem(14);
    bst.insertItem(2);

    int m = bst.maxBalancedHeight();
    cout << "max height for Balanced: " << m <<endl;

    int n = 12;
    int* inner = bst.inorderTraversal(n);
    cout << "array:  ";
    for (int i = 0; i < 12; i++)
        cout << inner[i] << " , ";
    cout<<""<<endl;




    bst.deleteItem(3);
    n = 11;
    inner = bst.inorderTraversal(n);
    cout<<"array:  ";
    for (int i=0;i<11;i++)
        cout<<inner[i]<<" , ";
    cout<<""<<endl;

    cout << "nodes deeper than 2: "<< bst.countNodesDeeperThan(2)<< endl;
    int* outer;
    outer = new int[6];
    outer[0]=1;
    outer[1]=2;
    outer[2]=3;
    outer[3]=4;
    outer[4]=5;
    outer[5]=6;
    bool result = bst.containsSequence(outer,6);
    cout<<"contain seq is: "<<boolalpha<<result<<endl;

    return 0;
}
