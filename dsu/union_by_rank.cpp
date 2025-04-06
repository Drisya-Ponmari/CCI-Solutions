#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Rank can also be considered as depth

void make_set(int v, int* parent, int* rank){
    parent[v] = v;
    rank[v] = 0;
}

int find_set(int v, int* parent){
    if(v == parent[v]) return v;
    return find_set(parent[v], parent);
}



void union_sets(int a, int b, int* parent, int* rank){
    int aRoot = find_set(a, parent);
    int bRoot = find_set(b, parent);
    if(aRoot == bRoot) return;
    
    if(rank[aRoot] < rank[bRoot]){
       swap(aRoot, bRoot);
    }
    parent[bRoot] = aRoot;
    if(rank[aRoot] == rank[bRoot])
        rank[aRoot]++;
    return;
}

int main(){
    int n;
    int a[n],parent[n],size[n];
    cin >> n;
    // should be 0 to n-1
    for(int i = 0; i < n; i++)
        cin >> a[i];
}