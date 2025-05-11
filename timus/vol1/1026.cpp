// Boost my confidence
#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> db(n);
    for(int i = 0; i < n; i++)
        cin >> db[i];
    sort(db.begin(), db.end());
    string s;
    cin >> s;
    int k;
    cin >> k;
    for(int i = 0; i < k; i++){
        int index;
        cin >> index;
        cout << db[index-1] << endl;
    }
    return 0;
}