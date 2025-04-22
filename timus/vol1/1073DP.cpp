#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
   int n;
   cin >> n;
   int dp[n+1];
   dp[0] = 0;
   int t = sqrt(n);
   for(int i = 1; i <= n; i++){
        int st = sqrt(i);
        if(st * st == i){
            dp[i] = 1;
        }else{
           int temp = dp[1] + dp[i-1];
           for(int k = 1; k*k < i; k++){
               temp = min(temp, dp[i- k*k] + 1);
           }
           dp[i] = temp;
        }
   }
   cout << dp[n] << endl;
    return 0;
}