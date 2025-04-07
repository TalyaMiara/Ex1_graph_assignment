//taliyam123@gmail.com

#ifndef ALGOHRITHMS_H
#define ALGOHRITHMS_H
#include "Graph.hpp"
#include "Queue.hpp"
#include "MinHeap.hpp"
#include "UnionFind.hpp"
#include <limits.h>
namespace graph{
    class Algorithms{
        public:
            Graph BFS(Graph& g, int src,int* dist=nullptr);
            Graph DFS(Graph& g, int src,int* disc=nullptr, int* fin=nullptr);
            Graph dijkstra(Graph& g,int src,int* arr=nullptr);
            Graph prim(Graph& g);
            Graph kruskal(Graph& g);
        private:
            void DFSVisit(Graph& g, int u, int* visited, int* parent, Graph& dfsTree, int* discovery, int* finish, int& time);
            void realx(int u,int v,int weight,int* distance,int* parent,MinHeap& minHeap);
    };
}
#endif