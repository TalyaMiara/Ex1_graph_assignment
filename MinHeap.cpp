//taliyam123@gmail.com
#include "MinHeap.hpp"
using namespace graph;

MinHeap::MinHeap(int size)
{
    if(size<=0){
        throw std::underflow_error("the size of the min heap should be up to 0");
    }
    this->size=size;
    this->minHeap=new int[size];
    for(int i=0; i<size;i++){
        minHeap[i]=INT_MAX;

    }
}
//destructor
MinHeap::~MinHeap()
{
    delete[] minHeap;
}

void MinHeap::insert(int index,int value){
    if(index<0||index>=size){
        throw std:: invalid_argument("the value of the index should be between 0 to size");
    }
    this->minHeap[index]=value;

}
int MinHeap::extractMin(){
  
    int minVal=minHeap[0];
    int index=0;
    for(int i=0;i<size;i++){
       int temp=minHeap[i];
       if(temp<minVal){
            minVal=temp;
            index=i;
       } 
    }
    minHeap[index]=INT_MAX;
    return index;
}

bool MinHeap::isEmpty(){
    for (int i = 0; i < size; i++)
    {
        if(this->minHeap[i]<INT_MAX){
            return false;
        }
    }
    
    return true;
}

