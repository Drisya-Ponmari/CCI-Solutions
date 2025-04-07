// Boost my confidence
#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
    int a;
    cin >> a;
    int sum = abs(a) * (abs(a)+1)/2;
    if(a == 0) cout << 1 << endl;
    else if(a < 0) cout << -1 * (sum-1) << endl;
    else cout << sum << endl;
}