//taliyam123@gmail.com
#include "main.hpp"
using namespace graph;

int main() {
    // Graph g(10) ;
    // Queue q=Queue();
    // q.enqueue(12);
    // q.enqueue(8);
    // q.enqueue(5);
    // int x=q.dequeue();
    // int y=q.peek();
    // int y2=q.dequeue();
    // q.dequeue();
    // std::cout<<"x is: "<<x<<" y is: "<<y<<" y2 is: "<<y2<<std::endl;    
    // g.addEdge(0, 1, 10);
    // g.addEdge(0, 4, 20);
    // g.addEdge(1, 2, 30);
    // g.addEdge(1, 3, 40);
    // g.addEdge(2, 3, 60);
    // g.addEdge(3, 4, 70);
    // g.addEdge(1, 4, 50);
    // g.addEdge(2, 5, 40);
    // g.addEdge(3, 6, 30);
    // g.addEdge(2, 6, 7);
    // g.addEdge(5, 7, 30);
    // g.addEdge(5, 8, 40);
    // g.addEdge(0, 8, 50);
    // g.addEdge(7, 9, 50);
    // g.addEdge(3, 9, 10);
    // g.print_graph();

    // MinHeap heap(5);
    // heap.insert(0,12);
    // heap.insert(1,8);
    // heap.insert(2,2005);
    // heap.insert(3,28);
    // heap.insert(4,17);
    // int min0=heap.extractMin();
    // int min1=heap.extractMin();
    // int min2=heap.extractMin();
    // int min3=heap.extractMin();

    // Graph bfs_try(9);
    // bfs_try.addEdge(0,1);
    // bfs_try.addEdge(0,5);
    // bfs_try.addEdge(2,1);
    // bfs_try.addEdge(7,1);
    // bfs_try.addEdge(0,7);
    // bfs_try.addEdge(2,1);
    // bfs_try.addEdge(2,6);
    // bfs_try.addEdge(5,4);
    // bfs_try.addEdge(5,8);
    // bfs_try.addEdge(6,7);
    // bfs_try.addEdge(6,8);
    // bfs_try.addEdge(7,8);
    Algorithms a;

    // Graph dfs_try(9);
    // dfs_try.addEdge(0,1);
    // dfs_try.addEdge(0,5);
    // dfs_try.addEdge(7,1);
    // dfs_try.addEdge(0,7);
    // dfs_try.addEdge(2,1);
    // dfs_try.addEdge(2,6);
    // dfs_try.addEdge(5,4);
    // dfs_try.addEdge(5,8);
    // dfs_try.addEdge(6,7);
    // dfs_try.addEdge(6,8);
    // dfs_try.addEdge(7,8);
    // dfs_try.addEdge(3,4);
    // dfs_try.addEdge(3,2);
    // dfs_try.addEdge(3,6);
    // Graph b=a.BFS(bfs_try,0);
    // Graph d1=a.DFS(dfs_try,0);
    // Graph d2=a.BFS(dfs_try,0);
    // std::cout<<"The bfs resualt is:"<<std::endl;
    // b.print_graph();
    // std::cout<<"The dfs first resualt is:"<<std::endl;
    // d1.print_graph();
    // Graph b=a.BFS(bfs_try,0);
    // b.print_graph();

    // Graph d(4);
    // d.addEdge(0,1,10);
    // d.addEdge(0,2,5);
    // d.addEdge(1,2,4);
    // d.addEdge(2,3,1);
    // d.addEdge(1,3,2);
    // Graph after=a.dijkstra(d,0);
    // after.print_graph();

    // Graph g(9);
    // g.addEdge(0, 1, 9);  // a - b
    // g.addEdge(0, 3, 1);  // a - d
    // g.addEdge(1, 2, 3);  // b - c
    // g.addEdge(1, 4, 4);  // b - e
    // g.addEdge(1, 5, 3);  // b - f
    // g.addEdge(2, 3, 5);  // c - d
    // g.addEdge(2, 5, 12);  // c - f
    // g.addEdge(2, 4, 1); // c - e
    // g.addEdge(3, 6, 8);  // d - g
    // g.addEdge(4, 8, 6);  // e - i
    // g.addEdge(5, 7, 2);  // f - h
    // g.addEdge(5, 6, 5); // f - g
    // g.addEdge(6, 7, 2);  // g - h
    // g.addEdge(7, 8, 1);  // h - i
    // g.addEdge(7, 5, 2);  // h - f
    // Graph kruskalGraph=a.kruskal(g);
    // kruskalGraph.print_graph();

    // UnionFind unionFind(10);
    // unionFind.unionn(2,3);
    // int f1=unionFind.find(2);
    // int f2=unionFind.find(3);
    // int f3=unionFind.find(5);
    // unionFind.unionn(2,4);
    // std::cout<<"f1: "<<f1<<" f2: "<<f2<<" f3: "<<f3<<std::endl;

    Graph g(9);
    g.addEdge(0, 1, 9);  // a - b
    g.addEdge(0, 3, 1);  // a - d
    g.addEdge(1, 2, 3);  // b - c
    g.addEdge(1, 4, 4);  // b - e
    g.addEdge(1, 5, 3);  // b - f
    g.addEdge(2, 3, 5);  // c - d
    g.addEdge(2, 5, 12);  // c - f
    g.addEdge(2, 4, 1); // c - e
    g.addEdge(3, 6, 8);  // d - g
    g.addEdge(4, 8, 6);  // e - i
    g.addEdge(5, 7, 2);  // f - h
    g.addEdge(5, 6, 5); // f - g
    g.addEdge(6, 7, 2);  // g - h
    g.addEdge(7, 8, 1);  // h - i
    g.addEdge(7, 5, 2);  // h - f
    // Graph kruskalGraph=a.kruskal(g);
    Graph primGraph=a.prim(g);
    // std::cout<<"KRUSKAL:"<<std::endl<<std::endl;
    // kruskalGraph.print_graph();
    // std::cout<<"PRIM:"<<std::endl<<std::endl;
    primGraph.print_graph();

    return 0;
}