/**
* Title : Heaps and AVL Trees
* Author : Hassan Raza
* ID: 21701811
* Section : 1
* Assignment : 3
* Description : header file for huffman queue
*/


#ifndef __HuffmanQueue_H
#define __HuffmanQueue_H

#include "HuffmanHeap.h"

class HuffmanQueue {
public:
	bool hqIsEmpty();
	void hqInsert(HuffmanHeap::MinHeapNode *newItem);
	void hqDelete(HuffmanHeap::MinHeapNode *&priorityItem);
    int size();
private:
	HuffmanHeap h;
};

#endif // HUFFMANQUEUE_H



