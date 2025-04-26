// Boost my confidence
#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
    int n, m;
    cin >> n;
    map<int,int> first;
    int x;
    for(int i = 0; i < n; i++){
        cin >> x;
        first[x] = 1;
    }
    cin >> m;
    map<int,int> second;
    for(int i = 0; i < m; i++){
        cin >> x;
        second[x] = 1;
    }

   for(auto val: first){
    int required = 10000 - val.first;
    if(second.find(required) != second.end()){
        cout << "YES" << endl;
        return 0;
    }
   }
   cout << "NO" << endl;
   return 0;
}