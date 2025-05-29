// Boost my confidence
#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    vector<int> x;
    vector<int> y;
    while(t--){
        int a,b;
        cin >> a >>b;
        x.push_back(a);
        y.push_back(b);
    }

    int cnt = 0;
    for(int i = 0; i < x.size(); i++){
        for(int j = i+1; j < x.size(); j++){
            int dx = x[j] - x[i];
            int dy = y[j] - y[i];
            int ans = 0;
            for(int k = 0; k < x.size(); k++){
                int second = dy*x[k] + dx*y[i] - dy*x[i];
                if( (dx * y[k]) == second) ans++;
            }
            cnt = max(cnt, ans);
        }

    }
    cout << cnt;
    return 0;
}