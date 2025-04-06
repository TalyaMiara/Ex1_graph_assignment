//taliyam123@gmail.com
#include "Graph.hpp"
using namespace graph;
Graph::Graph(int numOfVertex)
    {
        if(numOfVertex<=0){
            throw std:: invalid_argument("num of vertex must be positive");
        }
        this->numOfVertex=numOfVertex;
        this->numOfEdjes=0;
        this->adjacencyList=new Node* [numOfVertex];
        for (int i = 0; i < numOfVertex; i++) {
        adjacencyList[i] = nullptr; //initialized every pointer to nullptr
    }
    }
//destructor    
Graph::~Graph()
    {
        for (int i = 0; i < numOfVertex; i++) {
            //for each vertex we will delete him
            Node* current = adjacencyList[i];
            while (current) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] adjacencyList;
    }
void Graph::addEdge(int source, int target, int weight){
    if (source < 0 || source >= numOfVertex || target < 0 || target >= numOfVertex) {
        throw std::out_of_range("the edge is not exist");
    }
    Node* temp=adjacencyList[source];
    bool flag=false;
    while (temp!=nullptr)
    {
        if (temp->vertex==target)
        {
            flag=true;
            temp->weight=weight;
            break;
        }
        temp=temp->next;
    }
    if(!flag){    
        Node* node1=new Node(target,weight);
        node1->next = adjacencyList[source];
        adjacencyList[source] = node1;
        numOfEdjes++;
    }
    temp=adjacencyList[target];
    flag=false;
    while (temp!=nullptr)
    {
        if (temp->vertex==source)
        {
            flag=true;
            temp->weight=weight;
            break;
        }
        temp=temp->next;
    }
    if(!flag){
        
        Node* node2 = new Node(source, weight);
        node2->next = adjacencyList[target];
        adjacencyList[target] = node2;
        numOfEdjes++;
    }


    
}
void Graph::removeEdge(int num1,int num2){
    if (num1 < 0 || num1 >= numOfVertex || num2 < 0 || num2 >= numOfVertex) {
        throw std::out_of_range("the edge is not exist");
    }
    bool isFind = false;
    //delete frome the adjacenyList of num1
    Node* node1 = adjacencyList[num1];
    Node* prev1 = nullptr;
    while (node1 != nullptr) {
        if (node1->vertex == num2) {
            if (prev1 == nullptr) {
                // if this is the first node in the lise
                adjacencyList[num1] = node1->next;
            } else {
                prev1->next = node1->next;
            }
            numOfEdjes--;
            delete node1;
            isFind = true;
            break;
        }
        prev1 = node1;
        node1 = node1->next;
    }

    // delete frome the adjacenyList of num2
    Node* node2 = adjacencyList[num2];
    Node* prev2 = nullptr;
    while (node2 != nullptr) {
        if (node2->vertex == num1) {
            if (prev2 == nullptr) {
                // if this is the first node in the lise
                adjacencyList[num2] = node2->next;
            } else {
                prev2->next = node2->next;
            }
            numOfEdjes--;

            delete node2;
            isFind = true;
            break;
        }
        prev2 = node2;
        node2 = node2->next;
    }

    if (!isFind) {
        throw std::runtime_error("the edge is not exist");
    }

}
void Graph::print_graph(){
    for(int i=0; i<numOfVertex;i++){
        std::cout << "the vertex" << i << "connected to:";
        Node* current=adjacencyList[i];
        while (current)
        {
            std::cout << "(" << current->vertex << ",weight: " << current->weight << ") ";
            current = current->next;
        }
        std::cout << std::endl;
    }
}

Node** Graph::getAdjencyList(){
    return adjacencyList;
}
int Graph:: getNumOfVertex(){
    return numOfVertex;
}
int Graph:: getNumOfEdjes(){
    return this->numOfEdjes;
}

        