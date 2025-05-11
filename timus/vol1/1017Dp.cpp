// Beware of the data type
#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
   
   int n;
   cin >> n;
   long long dp[n+1][n+1];
   for(int i = 0; i <= n; i++){
    for(int j = 0; j <= n; j++){
       if(i == 0 && j > 0) dp[i][j] = 0;
       else if(i == 1 && j > 1) dp[i][j] = 0;
       else if(i == 1) dp[i][j] = 1;
       else if(j == 0) dp[i][j] = 1;
    }
   }
   for(int i =2; i <= n; i++){
    for(int j = 0; j <= n; j++){
        if(i > j) dp[i][j] = dp[i-1][j];
        else{
            dp[i][j] = dp[i-1][j] + dp[i-1][j-i];
        }
    }
   }
   cout << dp[n][n] - 1<< endl;
}