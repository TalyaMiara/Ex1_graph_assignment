#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Algorithms.hpp"
using namespace graph;
TEST_CASE("Graph"){
    SUBCASE("Graph creation"){
        CHECK_NOTHROW(Graph g(9));
        CHECK_THROWS_WITH(Graph g(-1),"num of vertex must be positive");
    }
    Graph g(9);
    SUBCASE("Add and Remove edges"){
        CHECK_NOTHROW(g.addEdge(0, 1, 9));
        CHECK_NOTHROW(g.addEdge(0, 3, 1));
        CHECK_NOTHROW(g.addEdge(1, 2, 3));
        CHECK_NOTHROW(g.addEdge(1, 4, 4));
        CHECK_NOTHROW(g.addEdge(1, 5, 3));
        CHECK_NOTHROW(g.addEdge(2, 3, 5));
        CHECK_NOTHROW(g.addEdge(2, 5, 12));
        CHECK_NOTHROW(g.addEdge(2, 4, 1));
        CHECK_NOTHROW(g.addEdge(3, 6, 8));
        CHECK_NOTHROW(g.addEdge(4, 8, 6));
        CHECK_NOTHROW(g.addEdge(5, 7, 2));
        CHECK_NOTHROW(g.addEdge(5, 6, 5));
        CHECK_NOTHROW(g.addEdge(6, 7, 2));
        CHECK_NOTHROW(g.addEdge(7, 8, 1));
        CHECK_NOTHROW(g.addEdge(7, 5, 2));
        CHECK_THROWS_WITH(g.addEdge(1,15,1),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(1,15),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(0,4),"the edge is not exist");
        CHECK_NOTHROW(g.removeEdge(0,3));
        CHECK_THROWS_WITH(g.removeEdge(0,3),"the edge is not exist");
    }
}

TEST_CASE("Min Heap"){
    MinHeap heap(5);
    heap.insert(0,3);
    heap.insert(1,5);
    heap.insert(2,50);
    heap.insert(3,2);
    heap.insert(4,17);
    //the extract min function return index
    int min=heap.extractMin();
    CHECK(min==3);
    CHECK(!heap.isEmpty());

    min=heap.extractMin();
    CHECK(min==0);
    CHECK(!heap.isEmpty());

    min=heap.extractMin();
    CHECK(min==1);
    CHECK(!heap.isEmpty());

    min=heap.extractMin();
    CHECK(min==4);
    CHECK(!heap.isEmpty());

    min=heap.extractMin();
    CHECK(min==2);
    CHECK(heap.isEmpty());
}

TEST_CASE("Union Find"){
    UnionFind uf(10);

    int f1=uf.find(2);
    CHECK(f1==2);

    f1=uf.find(3);
    CHECK(f1==3);

    uf.unionn(2,3);
    f1=uf.find(2);
    int f2=uf.find(3);
    CHECK(f1==f2);

    f1=uf.find(5);
    CHECK(f1==5);

    uf.unionn(2,4);
    f1=uf.find(2);
    f2=uf.find(3);
    int f3=uf.find(4);
    CHECK(f1==f2);
    CHECK(f2==f3);

}

TEST_CASE("Queue"){
    Queue q=Queue();
    q.enqueue(12);
    q.enqueue(8);
    q.enqueue(2005);
    int x=q.dequeue();
    CHECK(x==12);
    int y=q.peek();
    CHECK(y==8);
    int y2=q.dequeue();
    CHECK(y2==8);
    q.dequeue();
    CHECK_THROWS_WITH(q.dequeue(),"the queue is empty");
}

TEST_CASE("MST"){
    Algorithms a;
    Graph g2(9);
    g2.addEdge(0, 1, 9);  // a - b
    g2.addEdge(0, 3, 1);  // a - d
    g2.addEdge(1, 2, 3);  // b - c
    g2.addEdge(1, 4, 4);  // b - e
    g2.addEdge(1, 5, 3);  // b - f
    g2.addEdge(2, 3, 5);  // c - d
    g2.addEdge(2, 5, 12);  // c - f
    g2.addEdge(2, 4, 1); // c - e
    g2.addEdge(3, 6, 8);  // d - g
    g2.addEdge(4, 8, 6);  // e - i
    g2.addEdge(5, 7, 2);  // f - h
    g2.addEdge(5, 6, 5); // f - g
    g2.addEdge(6, 7, 2);  // g - h
    g2.addEdge(7, 8, 1);  // h - i
    g2.addEdge(7, 5, 2);  // h - f
    SUBCASE("kruskal"){
        Graph g=a.kruskal(g2);
        CHECK_NOTHROW(g.removeEdge(1,5));
        CHECK_NOTHROW(g.removeEdge(1,2));
        CHECK_NOTHROW(g.removeEdge(2,3));
        CHECK_NOTHROW(g.removeEdge(2,4));
        CHECK_NOTHROW(g.removeEdge(3,0));
        CHECK_NOTHROW(g.removeEdge(5,7));
        CHECK_NOTHROW(g.removeEdge(6,7));
        CHECK_NOTHROW(g.removeEdge(7,8));

        CHECK_THROWS_WITH(g.removeEdge(0,1),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(0,2),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(0,4),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(0,5),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(0,6),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(0,7),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(0,8),"the edge is not exist");
        
        CHECK_THROWS_WITH(g.removeEdge(1,0),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(1,3),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(1,4),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(1,6),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(1,7),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(1,8),"the edge is not exist");
        
        CHECK_THROWS_WITH(g.removeEdge(2,0),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(2,5),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(2,6),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(2,7),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(2,8),"the edge is not exist");

        CHECK_THROWS_WITH(g.removeEdge(3,1),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(3,4),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(3,5),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(3,6),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(3,7),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(3,8),"the edge is not exist");

        CHECK_THROWS_WITH(g.removeEdge(4,0),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(4,1),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(4,3),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(4,5),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(4,6),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(4,7),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(4,8),"the edge is not exist");

        CHECK_THROWS_WITH(g.removeEdge(5,0),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(5,2),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(5,3),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(5,4),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(5,6),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(5,8),"the edge is not exist");

        CHECK_THROWS_WITH(g.removeEdge(6,0),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(6,1),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(6,2),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(6,3),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(6,4),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(6,5),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(6,8),"the edge is not exist");

        CHECK_THROWS_WITH(g.removeEdge(7,0),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(7,1),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(7,2),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(7,3),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(7,4),"the edge is not exist");

        CHECK_THROWS_WITH(g.removeEdge(8,0),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(8,1),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(8,2),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(8,3),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(8,4),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(8,5),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(8,6),"the edge is not exist");


    }
    SUBCASE("prim"){
        Graph g=a.prim(g2);
        CHECK_NOTHROW(g.removeEdge(1,5));
        CHECK_NOTHROW(g.removeEdge(1,2));
        CHECK_NOTHROW(g.removeEdge(2,3));
        CHECK_NOTHROW(g.removeEdge(2,4));
        CHECK_NOTHROW(g.removeEdge(3,0));
        CHECK_NOTHROW(g.removeEdge(5,7));
        CHECK_NOTHROW(g.removeEdge(6,7));
        CHECK_NOTHROW(g.removeEdge(7,8));

        CHECK_THROWS_WITH(g.removeEdge(0,1),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(0,2),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(0,4),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(0,5),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(0,6),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(0,7),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(0,8),"the edge is not exist");
        
        CHECK_THROWS_WITH(g.removeEdge(1,0),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(1,3),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(1,4),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(1,6),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(1,7),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(1,8),"the edge is not exist");
        
        CHECK_THROWS_WITH(g.removeEdge(2,0),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(2,5),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(2,6),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(2,7),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(2,8),"the edge is not exist");

        CHECK_THROWS_WITH(g.removeEdge(3,1),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(3,4),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(3,5),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(3,6),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(3,7),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(3,8),"the edge is not exist");

        CHECK_THROWS_WITH(g.removeEdge(4,0),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(4,1),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(4,3),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(4,5),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(4,6),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(4,7),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(4,8),"the edge is not exist");

        CHECK_THROWS_WITH(g.removeEdge(5,0),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(5,2),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(5,3),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(5,4),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(5,6),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(5,8),"the edge is not exist");

        CHECK_THROWS_WITH(g.removeEdge(6,0),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(6,1),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(6,2),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(6,3),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(6,4),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(6,5),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(6,8),"the edge is not exist");

        CHECK_THROWS_WITH(g.removeEdge(7,0),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(7,1),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(7,2),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(7,3),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(7,4),"the edge is not exist");

        CHECK_THROWS_WITH(g.removeEdge(8,0),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(8,1),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(8,2),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(8,3),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(8,4),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(8,5),"the edge is not exist");
        CHECK_THROWS_WITH(g.removeEdge(8,6),"the edge is not exist");

    }

}


