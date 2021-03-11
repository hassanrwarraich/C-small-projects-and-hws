/**
* Title : Heaps and AVL Trees
* Author : Hassan Raza
* ID: 21701811
* Section : 2
* Assignment : 3
* Description : header file for a median heap
*/



#ifndef MEDIANHEAP_H
#define MEDIANHEAP_H

#include "MinHeap.h"
#include "MaxHeap.h"

class MedianHeap
{
    public:
        MedianHeap();
        void insert(int value ); // inserts an element into MedianHeap
        int findMedian(); // returns the value of the median

    private:
        MinHeap mini;
        MaxHeap maxi;
};

#endif // MEDIANHEAP_H
