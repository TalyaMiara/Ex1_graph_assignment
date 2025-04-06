//taliyam123@gmail.com
#include <iostream>
#include "Queue.hpp"
using namespace graph;
Queue::Queue()
{
   front=nullptr;
   rear=nullptr;
}
//the destructor
Queue::~Queue()
{
    while (front!=nullptr)
    {
        Node* temp=front;
        front=front->next;
        delete temp;
    }
}

void Queue::enqueue(int item){
    Node* node=new Node(item,0);
    if (front==nullptr)
    {
        front=node;
        rear=node;
    }else{
        rear->next=node;
        rear=rear->next;
    }
}
int Queue::dequeue(){
    if(front==nullptr){
        throw std::underflow_error("the queue is empty");
    }
    Node* node=front;
    int val=front->vertex;
    front=front->next;
    delete node;
    return val;
}

int Queue::peek(){
    if(front==nullptr){
        throw std::underflow_error("the queue is empty");
    }
    int val=front->vertex;
    return val;
    
}
bool Queue:: isEmpty(){
    return front==nullptr;
}
