// Boost my confidence
#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
    int n, m;
    cin >> n;
    vector<int> first;
    int x;
    for(int i = 0; i < n; i++){
        cin >> x;
        first.push_back(x);
    }
    sort(first.begin(), first.end());
    cin >> m;
    vector<int> second;
    for(int i = 0; i < m; i++){
        cin >> x;
        second.push_back(x);
    }
    sort(second.begin(), second.end(), greater<int>());
    int i = 0, j = 0;
    while(i < n && j < m){
        int curr = first[i] + second[j];
        if(curr == 10000) {
            cout << "YES" << endl;
            return 0;
        }
        else if(curr < 10000) i++;
        else j++;
    }
    cout << "NO" <<endl;
   return 0;
}