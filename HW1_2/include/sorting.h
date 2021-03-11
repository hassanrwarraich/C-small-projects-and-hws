/**
* Title : Algorithm Efficiency and Sorting
* Author : Hassan Raza
* ID: 21701811
* Section : 1
* Assignment : 1
* Description : this is a header file*/


#pragma once
#ifndef __MAC_H
#define __MAC_H
#include <string>
using namespace std;
class sorting {
public:
void bubbleSort(int *arr, int size, int &compCount, int &moveCount);
void quickSort(int *arr, int size, int &compCount, int &moveCount);
void mergeSort(int *arr, int size, int &compCount, int &moveCount);
void radixSort(int *arr, int size);
void merge( int *theArray, int first, int mid, int last, int &compCount, int &moveCount);
void mergesort( int *theArray, int first, int last, int &compCount, int &moveCount);
void partition(int *theArray, int first, int last, int &pivotIndex, int &compCount, int &moveCount);
void quicksort(int *theArray, int first, int last, int &compCount, int &moveCount);
void printArray(int *arr, int size);
int maxi(int *arr, int n);
void countSort(int *arr, int n, int exp);
void performanceAnalysis();
private:

};
#endif
