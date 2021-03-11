/**
* Title : Algorithm Efficiency and Sorting
* Author : Hassan Raza
* ID: 21701811
* Section : 1
* Assignment : 1
* Description : this code has different methods for sorting an array, it also has method for printing the array and a
* method that gives time needed by each sorting method for sorting an array*/


#include <string>
#include <iostream>
#include "sorting.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
//bubble sort
void sorting::bubbleSort(int *arr, int size, int &compCount, int &moveCount)
{
    bool sorted = false;
    //going through the array
	for (int pass = 1; (pass < size) && !sorted; ++pass)
    {
      sorted = true;
      //going through array after selecting a word
      for (int index = 0; index < size-pass; ++index)
      {
         int nextIndex = index + 1;
         compCount++;
         //checking for swaping
         if (arr[index] > arr[nextIndex])
         {
            moveCount = moveCount + 3;
            swap(arr[index], arr[nextIndex]);
            sorted = false;
         }
      }
   }
}


//start of quick sort
//partioing the array
void sorting::partition(int *theArray, int first, int last, int &pivotIndex, int &compCount, int &moveCount) {
    pivotIndex = 0;
    moveCount++;
    int pivot = theArray[first];
    int lastS1 = first;
    int firstUnknown = first + 1;
    //going through array
    for (  ; firstUnknown <= last; ++firstUnknown) {
        compCount++;
        //checking for swap
       if (theArray[firstUnknown] < pivot) {
		   ++lastS1;
		   moveCount = moveCount + 3;
    	   swap(theArray[firstUnknown], theArray[lastS1]);
       }
    }
    moveCount = moveCount + 3;
    swap(theArray[first], theArray[lastS1]);
    pivotIndex = lastS1;
}
//recusive method
void sorting::quicksort(int *theArray, int first, int last, int &compCount, int &moveCount) {
	int pivotIndex;
    if (first < last) {
       partition(theArray, first, last, pivotIndex, compCount, moveCount);
       quicksort(theArray, first, pivotIndex-1, compCount, moveCount);
       quicksort(theArray, pivotIndex+1, last, compCount, moveCount);
    }
}
//just calls next method with inreased parameters
void sorting::quickSort(int *arr, int size, int &compCount, int &moveCount)
{
    quicksort(arr, 0, size-1, compCount, moveCount);
}








//start of merge sort
const int MAX_SIZE = 60000;
//merging two arrays
void sorting::merge( int *theArray, int first, int mid, int last, int &compCount, int &moveCount) {
	int tempArray[MAX_SIZE];
	int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int index = first1;

    for ( ; (first1 <= last1) && (first2 <= last2); ++index) {
        compCount++;
       if (theArray[first1] < theArray[first2]) {
            moveCount++;
          tempArray[index] = theArray[first1];
          ++first1;
       }
       else {
           moveCount++;
           tempArray[index] = theArray[first2];
           ++first2;
       }
    }
    for (; first1 <= last1; ++first1, ++index)
    {
        tempArray[index] = theArray[first1];
        moveCount++;
    }
    for (; first2 <= last2; ++first2, ++index)
    {
        tempArray[index] = theArray[first2];
        moveCount++;
    }
    for (index = first; index <= last; ++index)
    {
        theArray[index] = tempArray[index];
        moveCount++;
    }
}
//recursive method
void sorting::mergesort( int *theArray, int first, int last, int &compCount, int &moveCount) {
	if (first < last) {
       int mid = (first + last)/2;
       mergesort(theArray, first, mid, compCount, moveCount);
       mergesort(theArray, mid+1, last, compCount, moveCount);
       merge(theArray, first, mid, last,compCount, moveCount);
    }
}
//method making call for next with increased parameters
void sorting::mergeSort(int *arr, int size, int &compCount, int &moveCount)
{
    mergesort(arr, 0, size-1, compCount, moveCount);
}





//start of radix sort
//sorting the array
void sorting::countSort(int *arr, int size, int exp)
{
    int finala[size];
    int group[10] = {0};
    //adding all elements in array deciding there number
    for (int i = 0; i < size; i++)
        group[ (arr[i]/exp)%10 ]++;
    //adding numbers for deciding place in final array
    for (int i = 1; i < 10; i++)
        group[i] += group[i - 1];
    //adding elements in final array
    for (int i = size - 1; i >= 0; i--)
    {
        finala[group[(arr[i] / exp) % 10] - 1] = arr[i];
        group[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < size; i++)
        arr[i] = finala[i];
}
//finding largest word i-e with most digits or characters
int sorting::maxi(int *arr, int size)
{
    int maxi = arr[0];
    for (int i = 1; i < size; i++){
        if (arr[i] > maxi){
            maxi = arr[i];
        }
    }
    return maxi;
}
//method making calls for other
void sorting::radixSort(int *arr, int size)
{
    int maxu = maxi(arr, size);
    for (int exp = 1; maxu/exp > 0; exp *= 10)
        countSort(arr, size, exp);
}





//printing the array
void sorting::printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] <<" , " ;
    }
    cout<<"\n";
}

//performance analysis showing performance of all sort methods
void sorting::performanceAnalysis()
{
    //making four arrays each storing data for one kind of sort algorithm
    double bubbleStore[32];
    int b = 0;
    double quickStore[32];
    int q = 0;
    double mergeStore[32];
    int w = 0;
    double radixStore[16];
    int r = 0;
    srand(time(0));
    //creating random array
    for (int m = 2000; m <= 30000; m = m+4000)
    {
        int bubbleArray[m];
        int quickArray[m];
        int mergeArray[m];
        int radixArray[m];
        bubbleStore[b++] = m;
        quickStore[q++] = m;
        mergeStore[w++] = m;
        radixStore[r++] = m;

        //copying random array into four so each algorithm can sort one array
        for (int i = 0; i < m; i++)
        {
            quickArray[i] = rand();
            bubbleArray[i] = quickArray[i];
            mergeArray[i] = quickArray[i];
            radixArray[i] = quickArray[i];
        }
        int compC = 0;
        int moveC = 0;

        //calculating time for bubble sort and storing in array
        clock_t begin = clock();
        bubbleSort(bubbleArray, m, compC, moveC);
        clock_t end = clock();
        double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
        bubbleStore[b++] = elapsed_secs*1000;
        bubbleStore[b++] = compC;
        bubbleStore[b++] = moveC;

        //calculating time for quick sort and storing in array
        compC = 0;
        moveC = 0;
        begin = clock();
        quickSort(quickArray, m, compC, moveC);
        end = clock();
        elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
        quickStore[q++] = elapsed_secs*1000;
        quickStore[q++] = compC;
        quickStore[q++] = moveC;

        //calculating time for merge sort and storing in array
        compC = 0;
        moveC = 0;
        begin = clock();
        mergeSort(mergeArray, m, compC, moveC);
        end = clock();
        elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

        mergeStore[w++] = elapsed_secs*1000;
        mergeStore[w++] = compC;
        mergeStore[w++] = moveC;

        //calculating time for radix sort and storing in array
        begin = clock();
        radixSort(radixArray, m);
        end = clock();
        elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
        radixStore[r++] = elapsed_secs*1000;


    }


    b=0;
    q=0;
    w=0;
    r=0;
    //printing radix sort data
    cout<<"-------------------------------"<<endl;
    cout<<"time analysis of radix sort "<<endl;
    cout <<"array Size\ttime elapsed"<<endl;
    for(int i = 0; i < 8; i++)
    {
        cout<<radixStore[i*2]<<"\t\t"<<radixStore[i*2+1]<<endl;
    }
    //printing bubble sort data
    cout<<"-------------------------------"<<endl;
    cout<<"time analysis of bubble sort "<<endl;
    cout <<"array Size\ttime elapsed\tcompCount\tmoveCount"<<endl;
    for(int i = 0; i < 8; i++)
    {
        cout<<bubbleStore[i*4]<<"\t\t"<<bubbleStore[i*4+1]<<"\t\t";
        cout<<bubbleStore[i*4+2]<<"\t"<<bubbleStore[i*4+3]<<endl;
    }
    //printing merge sort data
    cout<<"-------------------------------"<<endl;
    cout<<"time analysis of merge sort "<<endl;
    cout <<"array Size\ttime elapsed\tcompCount\tmoveCount"<<endl;
    for(int i = 0; i < 8; i++)
    {
        cout<<mergeStore[i*4]<<"\t\t"<<mergeStore[i*4 + 1]<<"\t\t";
        cout<<mergeStore[i*4 + 2]<<"\t\t"<<mergeStore[i*4 + 3]<<endl;
    }
    //printing quick sort data
    cout<<"-------------------------------"<<endl;
    cout<<"time analysis of quick sort "<<endl;
    cout <<"array Size\ttime elapsed\tcompCount\tmoveCount"<<endl;
    for(int i = 0; i < 8; i++)
    {
        cout<<quickStore[i*4]<<"\t\t"<<quickStore[i*4+1]<<"\t\t";
        cout<<quickStore[i*4+2]<<"\t\t"<<quickStore[i*4+3]<<endl;
    }



}
