// Bitmask : Accepted
#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
   
   int n;
   cin >> n;
   vector<int> w(n);
   for(int i = 0; i < n; i++){
    cin >> w[i];
   }

    int possibleCombinations =  1 << n;
    int minPossible = INT_MAX;
    for(int i =0; i < possibleCombinations; i++){
        int pile1 = 0;
        int pile0 = 0;
        for(int j = 0; j < n; j++){
            if( (i >> j) & 1)pile1 += w[j];
            else pile0 += w[j];
        }
        minPossible = min(minPossible, abs(pile0 - pile1));
    }
    cout << minPossible << endl;
}