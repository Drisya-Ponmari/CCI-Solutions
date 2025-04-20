#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int all(int n){
    vector<int> blah;
    blah.push_back(0);
    blah.push_back(1);
     int maxi = 1;
    for(int i = 2 ; i <= n; i++){
        if(i%2 ==0)
            blah.push_back(blah[i/2]);
        else 
            blah.push_back(blah[i/2] + blah[(i/2)+1]);
        maxi = max(maxi,blah[i]);
    }
    return maxi;
}
int main(){
   int t;
   while(cin >> t){
    if(t == 0) return 0;
    cout << all(t) << endl;
   }
}