//Do bfs
#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

//stack 
void dfs(vector<vector<int>>& gr, vector<int>& visited, vector<int>& order, int src){
    if(visited[src]==2) return;
    stack<int> s;
    s.push(src);
    visited[src] = 1;
    while (!s.empty())
    {
        int u = s.top();
        int non_visited_neighbour_count=0;
       vector<int> nei = gr[u];
       for(int i = 0; i < nei.size(); i++){
        // If the exisiting neighbour visited value is 1 then it's a cycle.
        if(visited[nei[i]] != 2) {
            s.push(nei[i]);
            visited[src] = 1;
            non_visited_neighbour_count++;
        }
       }
       if(non_visited_neighbour_count == 0){
        s.pop();
        order.push_back(u);
        visited[u] = 2;
       }
    }
    
}
int main(){
    
    int n;
    cin >> n;
    vector<vector<int>> gr(n);
    for(int i = 0; i < n; i++){
        int x; 
        cin >> x;
        while(x != 0){
            x--;
            gr[i].push_back(x);
            cin >> x;
        }
    }

    vector<int> order;
    vector<int> visited(n, 0);
    for(int i = 0; i < n; i++)
        if(visited[i] == 0)
            dfs(gr, visited,order,i);
    for(int i = order.size()-1; i >=0; i--)
        cout << ++order[i] << " ";
    return 0;
}