//taliyam123@gmail.com
#include "MinHeap.hpp"
using namespace graph;

// Constructor to initialize the MinHeap with a given size
MinHeap::MinHeap(int size)
{
    // Check if the size is valid (greater than 0)
    if(size<=0){
        throw std::underflow_error("the size of the min heap should be up to 0");
    }
    this->size=size;// Set the size of the heap
    this->minHeap=new int[size];// Allocate memory for the heap array
    for(int i=0; i<size;i++){
        minHeap[i]=INT_MAX;// Initialize all values to INT_MAX (representing empty slots)

    }
}
//destructor
MinHeap::~MinHeap()
{
    delete[] minHeap;// Deallocate the memory for minHeap
}
// Insert a value at a specified index in the min heap
void MinHeap::insert(int index,int value){
    // Check if the index is valid
    if(index<0||index>=size){
        throw std:: invalid_argument("the value of the index should be between 0 to size");
    }
    this->minHeap[index]=value;

}
int MinHeap::extractMin(){
  
    int minVal=minHeap[0];
    int index=0;
    // Loop through the heap to find the actual minimum value

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

