// DP : Accepted
#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
   
   int n, totalSum = 0;
   cin >> n;
   vector<int> w(n);
   for(int i = 0; i < n; i++){
    cin >> w[i];
    totalSum += w[i];
   }

   int halfSum = totalSum/2;
   vector<bool>dp(halfSum+1, false);
   dp[0] = true;
   for(int weight : w){
      for(int tempSum = halfSum; tempSum >= weight && tempSum > 0; tempSum--){
         if(dp[tempSum - weight])
            dp[tempSum] = true;
      }
   }

   int maxPossibleHalfSum = INT_MIN;
   for(int i = 0; i <= halfSum; i++){
      if(dp[i])
         maxPossibleHalfSum =i; 
   }

   cout << abs(2*maxPossibleHalfSum - totalSum) << endl;
   return 0;
}