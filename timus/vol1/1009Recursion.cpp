// Recursion: TLE
#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

long long ans = 0;
bool isValid(vector<int>& digits){
    if(digits[0] == 0) return false;
    for(int i = 1; i < digits.size(); i++){
        if(digits[i] == 0 && digits[i-1] == 0) return false;
    }
    return true;
}
void generate(vector<int>& digits, int k, int n){
    if(digits.size() == n){
        if(isValid(digits)) ans++;
    return;
    }
    for(int i = 0; i < k; i++){
        vector<int> temp = digits;
        temp.push_back(i);
        generate(temp, k,n);
    }
    return;
}

int main(){
   int n, k;
   cin >> n >> k;
   vector<int> temp;
   generate(temp, k,n);
   cout << ans << endl;
   return 0;
}