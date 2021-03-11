/**
* Title : Algorithm Efficiency and Sorting
* Author : Hassan Raza
* ID: 21701811
* Section : 1
* Assignment : 1
* Description : this has main method it creates an array, calls different sorting methods to print then calls
* performance analysis method*/


#include <iostream>
#include <iomanip>
#include "sorting.h"
using namespace std;

int main()
{
    //creating an array
    sorting object;
    int numbers[16];
    int numbers1[16];
    int numbers2[16];
    int numbers3[16];
    numbers[0] = 7;
    numbers[1] = 3;
    numbers[2] = 6;
    numbers[3] = 12;
    numbers[4] = 13;
    numbers[5] = 4;
    numbers[6] = 1;
    numbers[7] = 9;
    numbers[8] = 15;
    numbers[9] = 0;
    numbers[10] = 11;
    numbers[11] = 14;
    numbers[12] = 2;
    numbers[13] = 8;
    numbers[14] = 10;
    numbers[15] = 5;
    //copying array
    for (int i = 0; i < 16; i++)
    {
        numbers1[i] = numbers[i];
        numbers2[i] = numbers[i];
        numbers3[i] = numbers[i];
    }
    int a;
    int b;
    //sorting array
    object.bubbleSort(numbers, 16,a,b);
    object.quickSort(numbers1, 16,a,b);
    object.mergeSort(numbers2, 16,a,b);
    object.radixSort(numbers3, 16);
    object.printArray(numbers,16);
    object.printArray(numbers1,16);
    object.printArray(numbers2,16);
    object.printArray(numbers3,16);
    //calling performance
    object.performanceAnalysis();
}

