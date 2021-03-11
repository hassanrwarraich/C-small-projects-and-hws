#include <iostream>
#include "MedianHeap.h"
using namespace std;

int  main()
{
    MedianHeap median;
    cout<<median.findMedian()<<endl;
    median.insert(1);
    median.insert(2);
    median.insert(3);
    median.insert(4);
    median.insert(5);
    median.insert(6);
    cout<<median.findMedian()<<endl;
    return 0;
}

