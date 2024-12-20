
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
      unordered_map<int,vector<int>> list; 
    
    // Directed
    void addEdge(int u, int v){
        list[u].push_back(v);
    }

    //Undirected
    void addEdgeUndirected(int u, int v){
        list[u].push_back(v);
        list[v].push_back(u);
    }

    void print(){
        for(auto entry: list){
            cout << entry.first << ": ";
            for(int j = 0; j < entry.second.size(); j++)
                cout << entry.second[j] << " ";
            cout << endl;
        }
    }
};

#endif // GRAPH_H