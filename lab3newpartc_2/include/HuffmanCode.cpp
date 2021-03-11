/**
* Title : Heaps and AVL Trees
* Author : Hassan Raza
* ID: 21701811
* Section : 1
* Assignment : 3
* Description : huffman code making a tree from a queue
*/


#include "HuffmanCode.h"
#include <iostream>

using namespace std;

HuffmanHeap::MinHeapNode* HuffmanCode::Huffman(HuffmanQueue kyun)
{
    int n = kyun.size();
    for (int i = 1; i <= n-1; i++)
    {
        HuffmanHeap::MinHeapNode* total = new HuffmanHeap::MinHeapNode();
        kyun.hqDelete(total->left);
        kyun.hqDelete(total->right);
        total->freq = total->left->freq + total->right->freq;
        kyun.hqInsert(total);
    }

    HuffmanHeap::MinHeapNode* akhri = new HuffmanHeap::MinHeapNode();
    kyun.hqDelete(akhri);
    return akhri;
}


