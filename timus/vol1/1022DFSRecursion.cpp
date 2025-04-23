//Do bfs
#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

//stack 
void dfs(vector<vector<int>>& gr, vector<bool>& visited, vector<int>& order, int src){
    vector<int> nei = gr[src];
    for(int i = 0; i < nei.size(); i++)
        if(!visited[nei[i]])
            dfs(gr, visited, order, nei[i]);
    visited[src] = true;
    order.push_back(src);
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
    vector<bool> visited(n, false);
    for(int i = 0; i < n; i++)
        if(!visited[i])
            dfs(gr, visited,order,i);
    for(int i = order.size()-1; i >=0; i--)
        cout << ++order[i] << " ";
    return 0;
}