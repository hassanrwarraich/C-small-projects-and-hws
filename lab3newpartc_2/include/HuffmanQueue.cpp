/**
* Title : Heaps and AVL Trees
* Author : Hassan Raza
* ID: 21701811
* Section : 1
* Assignment : 3
* Description : huffman queue implementing a priority queue based on freq value
*/



#include "HuffmanQueue.h"
#include <iostream>

using namespace std;
bool HuffmanQueue::hqIsEmpty(){
	return h.heapIsEmpty();
}

void HuffmanQueue::hqInsert(HuffmanHeap::MinHeapNode *newItem){
		h.insert(newItem);
}

void HuffmanQueue::hqDelete(HuffmanHeap::MinHeapNode *&priorityItem){
		priorityItem = h.extractMin();
}

int HuffmanQueue::size()
{
    return h.size();
}



