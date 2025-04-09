// Boost my confidence. Accepted
#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int minDifferenceSofar = INT_MAX;
int totalSum  = 0;
void doPile(vector<int>& w, int index, int sumSoFar, int pileOneSum){

    if(sumSoFar == totalSum){
        minDifferenceSofar = min(abs(2*pileOneSum - totalSum), minDifferenceSofar);
        return;
    }
    if(index >= w.size()) return;

    // Take index in first pile
    doPile(w, index+1, sumSoFar+w[index], pileOneSum+w[index]);
    // Take index in the second pile
    doPile(w, index+1, sumSoFar+w[index], pileOneSum);
    return;
}
int main(){
   
   int n;
   cin >> n;
   vector<int> w(n);
   for(int i = 0; i < n; i++){
    cin >> w[i];
    totalSum += w[i];
   }

   doPile(w,0,0,0);
   cout << minDifferenceSofar << endl;
   return 0;
}