
// DP - Accepted
#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
   int n, k;
   cin >> n >> k;
   vector<int> temp;
   
   vector<int>numbers(n+1);
   numbers[0] = 1;
   numbers[1] = k-1;
   for(int i=2; i <=n; i++){
    numbers[i] = (k-1) * (numbers[i-1] + numbers[i-2]);
   }
   cout << numbers[n] << endl;
   return 0;
}