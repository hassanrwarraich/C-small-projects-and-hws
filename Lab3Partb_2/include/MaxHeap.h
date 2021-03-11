/**
* Title : Heaps and AVL Trees
* Author : Hassan Raza
* ID: 21701811
* Section : 2
* Assignment : 3
* Description : header file for a maxheap
*/


#ifndef MAXHEAP_H
#define MAXHEAP_H

int const MAX_HEAP = 100;

class MaxHeap {
public:
	MaxHeap();
	bool heapIsEmpty() const;

	void insert (int value ); // inserts integer into heap
    int peek (); // returns the value of the max element
    int extractMax (); // retrieves and removes the max element
    int size();

protected:
	void heapRebuild(int root);		// Converts the semiheap rooted at
					        // index root into a heap
private:
	int items[MAX_HEAP];	// array of heap items
	int sizea;            	// number of heap items
};


#endif // MAXHEAP_H
