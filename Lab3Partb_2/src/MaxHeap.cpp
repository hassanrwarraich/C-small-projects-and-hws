/**
* Title : Heaps and AVL Trees
* Author : Hassan Raza
* ID: 21701811
* Section : 2
* Assignment : 3
* Description : an implementation of max heap creating a max heap
*/


#include "MaxHeap.h"

MaxHeap::MaxHeap() : sizea(0) {
}


bool MaxHeap::heapIsEmpty() const {
	return (sizea == 0);
}



void MaxHeap::insert(int newItem) {
    //if size is full go back
	if (sizea >= MAX_HEAP)
    {
        return;
    }


	// Place the new item at the end of the heap
	items[sizea] = newItem;

	// Trickle new item up to its proper position
	int place = sizea;
	int parent = (place - 1)/2;
	while ( (place > 0) && (items[place] > items[parent]) ) {
		int temp = items[parent];
		items[parent] = items[place];
		items[place] = temp;

		place = parent;
		parent = (place - 1)/2;
	}
 	++sizea;
}


int MaxHeap::extractMax() {
	if (heapIsEmpty()) {
		//throw "HeapException: Heap empty";
	}
	else {
        int rootItem;
		rootItem = items[0];
		items[0] = items[--sizea];
		//rebuild heap after deleting an element
		heapRebuild(0);
        return rootItem;
	}
}

int MaxHeap::size ()
{
    return sizea;
}

int MaxHeap::peek()
{
    if (!heapIsEmpty())
    {
        return items[0];
    }
}



void MaxHeap::heapRebuild(int root) {
	int child = 2 * root + 1; 	// index of root's left child, if any
	if ( child < sizea ) {
		// root is not a leaf so that it has a left child
		int rightChild = child + 1; 	// index of a right child, if any
		// If root has right child, find larger child
		if ( (rightChild < sizea) &&
		     (items[rightChild] >items[child]) )
			child = rightChild; 	// index of larger child

		// If root’s item is smaller than larger child, swap values
		if ( items[root] < items[child] ) {
			int temp = items[root];
			items[root] = items[child];
			items[child] = temp;

			// transform the new subtree into a heap
			heapRebuild(child);
		}
}
}

