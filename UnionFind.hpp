//taliyam123@gmail.com

#ifndef UNOINFIND_H
#define UNOINFIND_H
#include <iostream>
namespace graph{
    class UnionFind
    {
    private:
        int* parent;
        int size;
    public:
        UnionFind(int numOfVertex);
        ~UnionFind();
        int find(int index);
        void unionn(int index1, int index2);
    };
}






#endif