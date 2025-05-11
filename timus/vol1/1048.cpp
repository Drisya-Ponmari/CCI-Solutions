// Boost my confidence
#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
    
    int n,temp;
    cin >> n;
    int a[n],b[n];
    for(int i = 0; i < n; i++){
       cin >> a[i] >> b[i];
    }
    int carry = 0;
    vector<int> ans;
    for(int i = n-1; i >= 0; i--){
        temp = a[i] + b[i] + carry;
        ans.push_back(temp%10);
        carry = temp/10;
    }
    if(carry == 1) ans.push_back(1);
    for(int i = ans.size()-1; i >=0; i--){
        cout << ans[i];
    }
    return 0;
}