#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#include "Graph.h"

unordered_map<int, bool> initialize(Graph* g){
    unordered_map<int, bool> visited;
    for(auto i: g->list)
        visited[i.first] =false;
    return visited;
}
// Time complexity o(v+e) where v is the vertices and e is the edges. 
// BFS iterative approach can be implemented using queue. 
void bfs(Graph* g, int source, int n){
   unordered_map<int, bool> visited = initialize(g);
    queue<int> q;
    q.push(source);
    while(!q.empty()){
        int curr_node = q.front();
        cout << curr_node << "\n";
        q.pop();
        visited[curr_node] = true;
        vector<int> neighbours = g->list[curr_node];
        for(int i =0; i < neighbours.size(); i++){
            if(!visited[neighbours[i]])
                q.push(neighbours[i]);
        }
    }
}
int main(){
    Graph* graph = new Graph();
    /**
     * {1,2}, {1,3}, {2,4}
     */
    graph->addEdgeUndirected(1,2);
    graph->addEdgeUndirected(1,3);
    graph->addEdgeUndirected(2,4);
    graph->print();
    bfs(graph, 1, 4);
}