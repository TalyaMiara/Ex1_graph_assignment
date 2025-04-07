//taliyam123@gmail.com
#include "Algorithms.hpp"
using namespace graph;
// Breadth-First Search (BFS): Builds BFS tree and calculates distances from source node
Graph Algorithms:: BFS(Graph& g, int src,int* dist){
    int numOfVertex = g.getNumOfVertex();
    if(src<0||src>=numOfVertex){
        throw std:: invalid_argument("source shoulde be between 0 to the num of vertex");
    }
    
    Graph bfsTree(numOfVertex);

    // Initialize parent, distance, and visited arrays
    int* parent = new int[numOfVertex];
    int* distance = new int[numOfVertex];
    int* visited =new int[numOfVertex];

    for(int i=0; i<numOfVertex;i++){
        parent[i]=INT_MAX;
        distance[i]=INT_MAX;
        visited[i]=0;// 0 = white (unvisited)
    } 
    distance[src]=0;
    visited[src]=1;// 1 = gray (discovered)

    Queue queue=Queue();
    queue.enqueue(src);
    // Traverse graph level by level
    while (!queue.isEmpty())
    {
        int u=queue.dequeue();
        std::cout<<"u is: "<<u<<std::endl;
        Node* adjencyList=g.getAdjencyList()[u];
        while (adjencyList!=nullptr)
        {
            if (visited[adjencyList->vertex]==0)
            {
                queue.enqueue(adjencyList->vertex);
                visited[adjencyList->vertex]=1;
                parent[adjencyList->vertex]=u;
                distance[adjencyList->vertex]=distance[u]+1;
                bfsTree.addEdge(u,adjencyList->vertex);
            }
            adjencyList=adjencyList->next;
        }
        visited[u]=2; // 2 = black (finished)
    }
    // Copy distance array to output if needed
    if(dist!=nullptr){
        for (int i = 0; i < numOfVertex; i++)
        {
            dist[i]=distance[i];
        }
    }
    delete[] parent;
    delete[] visited;
    delete[] distance;
    return bfsTree;
}

// DFSVisit: Helper function for recursive depth-first traversal
void Algorithms::DFSVisit(Graph& g, int u, int* visited, int* parent, Graph& dfsTree, int* discovery, int* finish, int& time) {
    visited[u] = 1; 
    discovery[u] = ++time;

    Node* adjacencyList = g.getAdjencyList()[u];
    while (adjacencyList != nullptr) {
        int v = adjacencyList->vertex;
        if (visited[v] == 0) { 
            parent[v] = u;
            dfsTree.addEdge(u, v); 
            DFSVisit(g, v, visited, parent, dfsTree, discovery, finish, time);
        }
        adjacencyList = adjacencyList->next;
    }

    visited[u] = 2; 
    finish[u] = ++time;
}

// Depth-First Search (DFS): Visits all vertices and builds DFS tree
Graph Algorithms::DFS(Graph& g, int src,int* disc, int* fin) {
    int numOfVertex = g.getNumOfVertex();
    Graph dfsTree(numOfVertex);
    if(src<0||src>=numOfVertex){
        throw std::invalid_argument("source should be between 0 to num of vertex");
    }
    int* visited = new int[numOfVertex];
    int* parent = new int[numOfVertex];
    int* discovery = new int[numOfVertex];
    int* finish = new int[numOfVertex];
    int time = 0;
    // Initialize arrays
    for (int i = 0; i < numOfVertex; i++) {
        visited[i] = 0; 
        parent[i] = -1;
        discovery[i] = -1;
        finish[i] = -1;
    }
    DFSVisit(g, src, visited, parent, dfsTree, discovery, finish, time);

    // Ensure disconnected components are also visited
    for (int u = 0; u < numOfVertex; u++) {
        if (visited[u] == 0) {
            DFSVisit(g, u, visited, parent, dfsTree, discovery, finish, time);
        }
    }

    std::cout << "DFS Discovery and Finish Times:\n";
    for (int i = 0; i < numOfVertex; i++) {
        std::cout << "Vertex " << i << ": d=" << discovery[i] << ", f=" << finish[i] << std::endl;
    }
    // Copy discovery and finish times to output if needed
    if(disc!=nullptr){
        for (int i = 0; i < numOfVertex; i++)
        {
            disc[i]=discovery[i];
        }
        
    }
    if(fin!=nullptr){
        for (int i = 0; i < numOfVertex; i++)
        {
            fin[i]=finish[i];
        }
        
    }

    delete[] visited;
    delete[] parent;
    delete[] discovery;
    delete[] finish;

    return dfsTree;
}

// Dijkstra's Algorithm: Finds the shortest path from a single source to all vertices (no negative weights)
Graph Algorithms::dijkstra(Graph& g,int src,int* arr){
    int size= g.getNumOfVertex();
    if(src<0||src>=size){
        throw std:: invalid_argument("the value of source should be between 0 to num of vertex");
    }
    // Check for negative weights
    Node** allEdge=g.getAdjencyList();
    for(int i=0;i<size;i++){
        Node* temp=allEdge[i];
        while(temp!=nullptr){
            if(temp->weight<0){
                throw std::invalid_argument("the weight of every edge must not be negative number");
            }
            temp=temp->next;
    }
    }
    Graph tree(g.getNumOfVertex());
    int* distance=new int[size];
    int* parent=new int[size];
    MinHeap minHeap(size);

    // Initialize distances
    for ( int i = 0; i < size; i++)
    {
        distance[i]=INT_MAX;
        parent[i]=INT_MAX;
    }
    distance[src]=0;
    minHeap.insert(src,0);
    while(!minHeap.isEmpty()){
        int u=minHeap.extractMin();
        if(u!=src)
            tree.addEdge(u,parent[u],distance[parent[u]]);
        Node* adjencyList=g.getAdjencyList()[u];
        while(adjencyList!=nullptr){
            realx(u,adjencyList->vertex,adjencyList->weight,distance,parent,minHeap);
            adjencyList=adjencyList->next;
        }
    }
    if(arr!=nullptr){
        for (int i = 0; i < size; i++)
        {
            arr[i]=distance[i];
        }
    }
    delete[] distance;
    delete[] parent;
    return tree;
}

// Relaxation function used by Dijkstra to update distances
void Algorithms::realx(int u,int v,int weight,int* distance,int* parent,MinHeap& minHeap){
    if(distance[v]>(distance[u]+weight)){
        minHeap.insert(v,distance[u]+weight);
        parent[v]=u;
        distance[v]=distance[u]+weight;
    }
}

// Prim’s Algorithm: Builds a Minimum Spanning Tree (MST) using greedy edge selection
Graph Algorithms::prim(Graph& g){
    int n=g.getNumOfVertex();

    // First, ensure the graph is connected using BFS
    int* distance= new int[n]; 
    Graph bfsCheck=BFS(g,0,distance);
    bool booleanConnect=true;
    for (int i = 0; i < n; i++)
    {
        if(distance[i]==INT_MAX){
            booleanConnect=false;
            break;
        }
    }
    delete[] distance;
    if(!booleanConnect){
        throw std:: invalid_argument("the graph should be connected");
    }
    int* weight= new int[n];
    int* nearNeighbor = new int[n];
    for(int i=0;i<n;i++){
        weight[i]=INT_MAX;
        nearNeighbor[i]=INT_MAX;
    }

    // Start from a random node
    int s = rand() % n;// random number between 0 and n-1;
    Node* temp=g.getAdjencyList()[s];
    while (temp!=nullptr)
    {
        int k=temp->vertex;
        weight[k]=temp->weight;
        nearNeighbor[k]=s;
        temp=temp->next;   
    }
    Graph primGraph(n);
    UnionFind unionFind(n);
    int chosenEdge=0;

    // Add (n-1) edges to build the MST
    while(chosenEdge<n-1){
        // Find the edge with minimum weight
        int minIndex=0;
        for(int i=1;i<n;i++){
            if(weight[i]<weight[minIndex]){
                minIndex=i;
            }
        }
        primGraph.addEdge(nearNeighbor[minIndex],minIndex,weight[minIndex]);
        chosenEdge++;
        unionFind.unionn(s,minIndex);
        weight[minIndex]=INT_MAX;
        temp=g.getAdjencyList()[minIndex];
        while(temp!=nullptr){
            int x=temp->vertex;
            if(unionFind.find(x)!=unionFind.find(s)){
                if(weight[x]>temp->weight){
                    weight[x]=temp->weight;
                    nearNeighbor[x]=minIndex;
                }
            }
            temp=temp->next;
        }
    }
    delete[] weight;
    delete[] nearNeighbor;
    return primGraph;
}

// Kruskal’s Algorithm: Builds a Minimum Spanning Tree (MST) using a greedy edge selection
Graph Algorithms::kruskal(Graph& g){
    int numOfVertex=g.getNumOfVertex();

    // Step 1: Check if the graph is connected using BFS
    int* distance= new int[numOfVertex]; 
    Graph bfsCheck=BFS(g,0,distance);
    bool booleanConnect=true;
    for (int i = 0; i < numOfVertex; i++)
    {
        if(distance[i]==INT_MAX){
            booleanConnect=false;
            break;
        }
    }
    delete[] distance;
    if(!booleanConnect){
        throw std:: invalid_argument("the graph should be connected");
    }
    Node** allEdge=g.getAdjencyList();
    // Step 2: Count total unique edges (undirected edges counted once)
    int numOfEdges=(int)(g.getNumOfEdjes()/2);

    // Step 3: Create an array to store edges with their weights
    Node** sortEdges=new Node*[numOfEdges];
    Graph kruskalGraph(numOfVertex);
    int index=0;//the index of the new array- sortEdges
    // Step 4: Store each edge only once (i < neighbor) and encode the edge using i*numOfVertex + j
    for(int i=0;i<numOfVertex;i++){
        Node* temp=allEdge[i];
        while (temp!=nullptr && index<numOfEdges)
        {
            if(i<temp->vertex){
                // after this when I will want to find the real vertex they will be i/n , i%n;
                sortEdges[index++]=new Node(i*numOfVertex+temp->vertex,temp->weight);
            }
            temp=temp->next;
        }
    }
    // Step 5: Sort edges by weight using simple bubble sort
    for(int i=0;i<numOfEdges;i++){
        for(int j=0;j<numOfEdges-i-1;j++){
            if(sortEdges[j]->weight>sortEdges[j+1]->weight){
                Node* temp=sortEdges[j+1];
                sortEdges[j+1]=sortEdges[j];
                sortEdges[j]=temp;
            }
        }
    }
    // Step 6: Initialize Union-Find to manage disjoint sets

    UnionFind unionFind=UnionFind(numOfVertex);

    // Step 7: Go through sorted edges, add edge to MST if it doesn’t form a cycle
    for(int i=0;i<numOfEdges;i++){
        int u=sortEdges[i]->vertex/numOfVertex;
        int v=sortEdges[i]->vertex%numOfVertex;
        if(unionFind.find(u)!=unionFind.find(v)){
            unionFind.unionn(u,v);
            kruskalGraph.addEdge(u,v,sortEdges[i]->weight);
        }
        // Clean up allocated memory for edge
        delete sortEdges[i];
    }
    
    delete[] sortEdges;
    return kruskalGraph;
    
}