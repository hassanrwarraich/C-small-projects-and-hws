/**
* Title : Heaps and AVL Trees
* Author : Hassan Raza
* ID: 21701811
* Section : 1
* Assignment : 3
* Description : main class executing huffman code
*/




#include <iostream>
#include "HuffmanCode.h"
using namespace std;
#include <fstream>
#include <sstream>
void getArray(HuffmanHeap::MinHeapNode* node, string& length, string strings[], int& curr)
{

    if(node->left == NULL && node->right == NULL){
        strings[curr] = node->character;
        strings[curr+1] = length;
        curr = curr + 2;
    }


    length = length + "0";
    if(node->left != NULL)
        getArray(node->left, length, strings, curr);
    length = length.substr(0, length.length()-1);

    length = length + "1";
    if(node->right != NULL)
        getArray(node->right, length, strings, curr);
    length = length.substr(0, length.length()-1);
}

int  main(int argc, char *argv[])
{
    if ( argc != 3 )
        cout<<"unexpected arguments";
    else{
        ifstream infile(argv[1]);
        ofstream outfile(argv[2]);

        string agliLine;
        HuffmanQueue line;
        HuffmanCode code;
        while (getline(infile, agliLine))
        {
            istringstream agli(agliLine);
            int num;
            char digit;
            if (!(agli >> digit >> num))
            {
                break;
            }

            HuffmanHeap::MinHeapNode* next = new HuffmanHeap::MinHeapNode();
            next->character = digit;
            next->freq = num;
            next->left = NULL;
            next->right = NULL;

            line.hqInsert(next);
        }
        infile.close();
        HuffmanHeap::MinHeapNode* result = new HuffmanHeap::MinHeapNode();
        result = code.Huffman(line);
        string length = "";
        string arrays[128];
        int curr = 0;
        getArray(result, length, arrays, curr);
        for (int i = 0; i < curr; i=i+2)
        {
            outfile << arrays[i] << " " << arrays[i+1] << endl;
        }
        outfile.close();
    }
    return 0;
}







