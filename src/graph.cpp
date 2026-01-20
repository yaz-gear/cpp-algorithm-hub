#include "graph.h"
#include <limits>

Graph::Graph(int V){
    this->V=V;
    adj.resize(V);
}

void Graph::addEdge(int u,int v,int w){
    adj[u].push_back({v,w});
}

void Graph::BFS(int start){
    std::vector<bool> visited(V,false);
    std::queue<int> q;
    visited[start]=true;
    q.push(start);
    while(!q.empty()){
        int node = q.front(); q.pop();
        std::cout << node << " ";
        for(auto neighbor: adj[node]){
            if(!visited[neighbor.first]){
                visited[neighbor.first]=true;
                q.push(neighbor.first);
            }
        }
    }
    std::cout << std::endl;
}

void Graph::DFS(int start){
    std::vector<bool> visited(V,false);
    std::stack<int> s;
    s.push(start);
    while(!s.empty()){
        int node = s.top(); s.pop();
        if(!visited[node]){
            visited[node]=true;
            std::cout << node << " ";
            for(auto neighbor: adj[node]){
                if(!visited[neighbor.first])
                    s.push(neighbor.first);
            }
        }
    }
    std::cout << std::endl;
}

void Graph::dijkstra(int start){
    std::vector<int> dist(V,std::numeric_limits<int>::max());
    dist[start]=0;
    std::vector<bool> visited(V,false);
    for(int i=0;i<V;i++){
        int u=-1;
        for(int j=0;j<V;j++){
            if(!visited[j] && (u==-1 || dist[j]<dist[u])) u=j;
        }
        if(dist[u]==std::numeric_limits<int>::max()) break;
        visited[u]=true;
        for(auto neighbor: adj[u]){
            int v=neighbor.first,w=neighbor.second;
            if(dist[u]+w<dist[v]) dist[v]=dist[u]+w;
        }
    }
    std::cout << "Distances from node "<<start<<": ";
    for(int d: dist) std::cout << d << " ";
    std::cout << std::endl;
}
