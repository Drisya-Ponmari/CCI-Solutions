//Easy DFS
/**
 * Read the question carefully, that there is no entry and exit, both are entries. നന്ദി
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> M;
long long SIDES = 0;
vector<int> X = {0,0,-1,1};//l.r.u.d
vector<int> Y = {-1,1,0,0};
int N;
bool inBound(int x, int y){
    if(x <0 || y <0 || x >= N || y >= N)return false;
    return true;
}
bool isWall(int x, int y, int dir){
    if((x==0 && y==0) || (x == N-1 && y == N-1)) return false;
    if(M[x][y] == '#' ||
      (y == 0 && dir==0) || 
      (x == 0 && dir==2) ||
       (x == N-1&&dir==3) || 
       (y == N-1&&dir==1)) return true;
    return false;
}
int getWallAttached(int x, int y){
    int cnt = 0;
    for(int i=0; i < 4; i++){
        if(isWall(x, y,i)) cnt++;
    }
    for(int i =0; i <4; i++){
        if(inBound(x+X[i], y+Y[i]) && M[x+X[i]][y+Y[i]]=='#') cnt++;
    }
    return cnt;
}
void dfs(int x,int y){
    if(M[x][y] == 'v') return;
    M[x][y] = 'v';
    stack<pair<int,int>> s;
    s.push({x,y});
    while(!s.empty()){
        pair<int,int> node = s.top();
        s.pop();
        SIDES += getWallAttached(node.first, node.second);
        for(int i = 0; i < 4; i++){
            int new_x = node.first+X[i];
            int new_y = node.second+Y[i];
            if(!inBound(new_x, new_y)) continue;
            if(M[new_x][new_y] != 'v' && M[new_x][new_y] != '#'){
               M[new_x][new_y] = 'v';
               s.push({new_x,new_y});
            }
        }
    }
}
int main(){
    cin >> N;
    M.assign(N,vector<char>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> M[i][j];
        }
    }
    dfs(0,0);
    dfs(N-1,N-1);
    cout << SIDES * 3 * 3 <<endl;
    return 0;
}