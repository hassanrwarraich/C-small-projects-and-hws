/**
* Title : Heaps and AVL Trees
* Author : Hassan Raza
* ID: 21701811
* Section : 1
* Assignment : 3
* Description : header file for huffman heap
*/



#ifndef __HuffmanHeap_H
#define __HuffmanHeap_H
const int MINIS = 100;
class HuffmanHeap
{

    public:
        struct MinHeapNode
        {
            char character ; // An input character
            int freq ; // Frequency of the character
            MinHeapNode *left , * right ; // Left and right child
        };
        HuffmanHeap();
        bool heapIsEmpty() const;

        void insert (MinHeapNode* value ); // inserts integer into heap
        MinHeapNode* peek(); // returns the value of the max element
        MinHeapNode* extractMin(); // retrieves and removes the max element
        int size();


    protected:
        void heapRebuild(int root);

    private:
        MinHeapNode* items[MINIS];	// array of heap items
        int sizea;
};

#endif // HUFFMANHEAP_H
