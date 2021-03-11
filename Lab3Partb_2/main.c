#include <iostream>
#include "MedianHeap.h"
using namespace std;



int  main()
{
    MedianHeap median;
    median.insert(1);
    median.insert(2);
    median.insert(3);
    median.insert(4);
    median.insert(5);
    median.insert(6);
    median.insert(7);
    median.insert(8);
    median.insert(9);
    cout<<median.findMedian()<<endl;
    return 0;
}

