//taliyam123@gmail.com
#include <iostream>
#include <limits.h>
#ifndef MINHEAP_H
#define MINHEAP_H

namespace graph{
    class MinHeap
    {
    private:
        int* minHeap;
        int size;
    public:
        MinHeap(int size);
        ~MinHeap();

        void insert(int index,int value);
        int extractMin();
        bool isEmpty();
    };
   
}



#endif