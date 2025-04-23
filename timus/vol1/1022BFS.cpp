//Do bfs
#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

//kahns algorithm
void bfs(vector<int>& order, vector<int>& inDegree, vector<vector<int>>& gr, vector<bool>& visited, int src){
    if(visited[src]) return;
    order.push_back(src);
    queue<int> q;
    q.push(src);
    visited[src] = true;
    while (!q.empty())
    {
       int u = q.front();
       visited[u] = true;
       q.pop();
       vector<int> nei = gr[u];
       for(int i = 0; i < nei.size(); i++){
        inDegree[nei[i]]--;
        if(inDegree[nei[i]] == 0) {
            q.push(nei[i]);
            order.push_back(nei[i]);
        }
       }
    }
    return;
}
int main(){
    
    int n;
    cin >> n;
    vector<vector<int>> gr(n);
    vector<int> inDegree(n,0);
    for(int i = 0; i < n; i++){
        int x; 
        cin >> x;
        while(x != 0){
            x--;
            gr[i].push_back(x);
            inDegree[x]++;
            cin >> x;
        }
    }

    vector<int> order;
    vector<bool> visited(n, false);
    for(int i = 0; i < n; i++)
        if(inDegree[i] == 0)
            bfs(order,inDegree,gr,visited,i);
    for(int i = 0; i < order.size(); i++)
        cout << ++order[i] << " ";
    return 0;
}