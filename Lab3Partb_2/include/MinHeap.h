/**
* Title : Heaps and AVL Trees
* Author : Hassan Raza
* ID: 21701811
* Section : 2
* Assignment : 3
* Description : header file for a minheap
*/


#ifndef MINHEAP_H
#define MINHEAP_H


int const MIN_HEAP = 100;

class MinHeap {
public:
	MinHeap();
	bool heapIsEmpty() const;

	void insert (int value ); // inserts integer into heap
    int peek (); // returns the value of the max element
    int extractMin (); // retrieves and removes the max element
    int size();

protected:
	void heapRebuild(int root);		// Converts the semiheap rooted at
					        // index root into a heap
private:
	int items[MIN_HEAP];	// array of heap items
	int sizea;            	// number of heap items
};


#endif // MAXHEAP_H
