#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <limits>

class Graph {
private:
    int V;
    std::vector<std::vector<std::pair<int,int>>> adj; // pair<node,weight>
public:
    Graph(int V);
    void addEdge(int u,int v,int w=1);
    void BFS(int start);
    void DFS(int start);
    void dijkstra(int start);
};

#endif
