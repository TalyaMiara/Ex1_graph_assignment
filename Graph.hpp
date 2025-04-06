//taliyam123@gmail.com
#include <iostream>
#ifndef GRAPH_H
#define GRAPH_H

namespace graph{
    struct Node
    {
        int vertex;
        double weight;
        Node* next;
        Node(int vertex, double weight):vertex(vertex),weight(weight), next(nullptr){};
    };

    class Graph
    {
    private:
        int numOfEdjes;
        int numOfVertex;
        Node** adjacencyList;
    public:
        Graph(int numOfVertex);
        ~Graph();

        void addEdge(int source, int target, int weight=1);  
        void removeEdge(int num1,int num2); 
        void print_graph();
        Node** getAdjencyList();
        int getNumOfVertex();
        int getNumOfEdjes();

    };

    
    
   
    
}













#endif