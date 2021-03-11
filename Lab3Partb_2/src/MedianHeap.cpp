/**
* Title : Heaps and AVL Trees
* Author : Hassan Raza
* ID: 21701811
* Section : 2
* Assignment : 3
* Description : an implementation of median heap creating a median heap
*/


#include "MedianHeap.h"
#include "MinHeap.h"
#include "MaxHeap.h"

MedianHeap::MedianHeap()
{}

void MedianHeap::insert(int value)
{
    //inserting values
    if (value > findMedian())
        mini.insert(value);
    else
        maxi.insert(value);
    //balancing heap
    if (mini.size() > maxi.size() + 1)
        while (mini.size() > maxi.size() + 1)
            maxi.insert(mini.extractMin());
    if (maxi.size() > mini.size() + 1)
        while (maxi.size() > mini.size() + 1)
            mini.insert(maxi.extractMax());
}

int MedianHeap::findMedian()
{
    //check for null
    if (mini.size() == 0 && maxi.size() == 0) {
        return 0;
    }
    if(mini.size() < maxi.size())
        return maxi.peek();
    else
        return mini.peek();
}
