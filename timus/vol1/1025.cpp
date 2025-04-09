// Boost my confidence
#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
   
   // This is a greedy approach. 
   int k;
   cin >> k;
   vector<int> groups(k);
   for(int i =0; i <k; i++){
    cin >> groups[i];
   }
   sort(groups.begin(), groups.end());
   int ans = 0;
   for(int i = 0; i < (k/2)+1; i++){
    ans += (groups[i]/2)+1;
   }
   cout << ans << endl;
   return 0;
}