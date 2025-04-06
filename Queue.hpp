//taliyam123@gmail.com
#include <iostream>
#include "Graph.hpp"
#ifndef QUEUE_H
#define QUEUE_H
namespace graph{
    class Queue
    {
    private:
        Node* front;
        Node* rear;

    public:
        Queue();
        ~Queue();

        void enqueue(int item);//the value we will add the queue
        int dequeue();
        int peek();
        bool isEmpty();
        
    };
}
#endif




