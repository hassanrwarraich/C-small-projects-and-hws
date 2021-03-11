/**
* Title : Heaps and AVL Trees
* Author : Hassan Raza
* ID: 21701811
* Section : 1
* Assignment : 3
* Description : huffmanheap making a heap of pointers
*/



#include "HuffmanHeap.h"
#include <iostream>
using namespace std;

HuffmanHeap::HuffmanHeap() : sizea(0) {
}


bool HuffmanHeap::heapIsEmpty() const {
	return (sizea == 0);
}



void HuffmanHeap::insert(MinHeapNode* newItem) {

    if (sizea >= MINIS){
        cout<<"array full"<<endl;
		return;
	}

	// Place the new item at the end of the heap
	items[sizea] = newItem;

	// Trickle new item up to its proper position
	int place = sizea;
	int parent = (place - 1)/2;
    //cout << items[place]->freq << " place inserting" << endl;
    //cout << items[parent]->freq << " parent inserting" << endl;

	while ( (place > 0) && (items[place]->freq < items[parent]->freq) ) {
        //cout << items[place]->freq << " place inserting" << endl;
        //cout << items[parent]->freq << " parent inserting" << endl;
		MinHeapNode* temp = items[parent];
		items[parent] = items[place];
		items[place] = temp;

		place = parent;
		parent = (place - 1)/2;
	}
 	++sizea;
}


HuffmanHeap::MinHeapNode* HuffmanHeap::extractMin() {
	if (heapIsEmpty())
		return NULL;
	else {
        MinHeapNode* rootItem;
		rootItem = items[0];
		items[0] = items[--sizea];
		heapRebuild(0);
        return rootItem;
	}
}

int HuffmanHeap::size ()
{
    return sizea;
}

HuffmanHeap::MinHeapNode* HuffmanHeap::peek()
{
    if (!heapIsEmpty())
    {
        return items[0];
    }
    return NULL;
}



void HuffmanHeap::heapRebuild(int root) {
	int child = 2 * root + 1;
	if ( child < sizea ) {
		// root is not a leaf so that it has a left child
		int rightChild = child + 1; 	// index of a right child, if any
		// If root has right child, find larger child
		if ( (rightChild < sizea) && (items[rightChild]->freq < items[child]->freq) )
			child = rightChild; 	// index of larger child

		// If root’s item is smaller than larger child, swap values
		if ( items[root]->freq > items[child]->freq ) {
			HuffmanHeap::MinHeapNode* temp = items[root];
			items[root] = items[child];
			items[child] = temp;

			// transform the new subtree into a heap
			heapRebuild(child);
		}
    }
}
