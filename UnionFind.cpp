//taliyam123@gmail.com
#include "UnionFind.hpp"
using namespace graph;

 
UnionFind::UnionFind(int numOfVertex)
{
    if(numOfVertex<=0){
        throw std:: invalid_argument("num of vertex should be up to 0");
    }
    this->size=numOfVertex;
    this->parent=new int[size];
    for (int i = 0; i < size; i++)
    {
        parent[i]=i;
    }
    
}

UnionFind::~UnionFind()
{
    delete[] parent;
}

int UnionFind::find(int index){
    if(index<0||index>=size){
        throw std:: invalid_argument("index must be between 0 to size-1");
    }
    while(index!=parent[index]){
        index=parent[index];
    }
    return index;
}
void UnionFind::unionn(int index1, int index2){
    int s1=find(index1);
    int s2=find(index2);
    parent[s1]=s2;
}
