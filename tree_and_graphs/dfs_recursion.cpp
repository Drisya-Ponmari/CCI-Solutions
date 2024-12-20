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
void dfs(Graph* g, int source, unordered_map<int,bool> visited){
  cout << source << endl;
  visited[source] = true;
  vector<int> neighbours = g->list[source];
  for(int i =0; i < neighbours.size(); i++)
    if(!visited[neighbours[i]])
        dfs(g, neighbours[i], visited);
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
    unordered_map<int, bool> visited = initialize(graph);
    dfs(graph, 1, visited);
}