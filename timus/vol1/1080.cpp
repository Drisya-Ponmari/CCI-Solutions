// Boost my confidence
#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
//bfs
int getColor(int c){
    if(c == 1) return 2;
    return 1;
}
bool bfs(vector<vector<int>>& adj, vector<int>&colour, int src){
    if(colour[src] != 0) return true;
    colour[src] = 1;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        vector<int> neigbours = adj[u];
        for(int i = 0; i < neigbours.size(); i++){
            int v = neigbours[i];
            if(colour[v] == colour[u]){
                return false;
            }
            if(colour[v] != 0) continue;
            colour[v] = getColor(colour[u]);
            q.push(v);
        }
    }
    return true;
}
int main(){
   int n,x;
   cin >> n;
   vector<vector<int>> adj(n);
   for(int i = 0; i < n; i++){
    cin >> x;
    while(x!=0){
        x--;
        adj[i].push_back(x);
        adj[x].push_back(i);
        cin >> x;
    }
   }

   vector<int> colour(n,0);
   for(int i = 0; i <n; i++){
    bool isPossible = bfs(adj,colour,i);
    if(!isPossible){
        cout << -1 << endl;
        return 0;
    }
   }
   for(int i =0; i < n; i++)
    cout << --colour[i];
    return 0;
}