#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void make_set(int v, int* parent){
    parent[v] = v;
}

//o(n) time .. bad!!
int find_set(int v, int* parent){
    if(v == parent[v]) return v;
    return find_set(parent[v], parent);
}

// path compression o(logn)
int find_set(int v, int* parent){
    if(v == parent[v]) return v;
    return parent[v] = find_set(parent[v], parent);
}


void union_sets(int a, int b, int* parent){
    int aRoot = find_set(a, parent);
    int bRoot = find_set(b, parent);
    if(aRoot == bRoot) return;
    parent[aRoot] = bRoot;
    return;
}

int main(){
    int n;
    int a[n],parent[n];
    cin >> n;
    // should be 0 to n-1
    for(int i = 0; i < n; i++)
        cin >> a[i];
}