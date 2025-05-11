//TLE
#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

long ans = 0;
void didItReachI(int i, int sofar){
    if(sofar < 0) return;
    if(sofar == 0){
        ans++;
        return;
    }
    for(int next = i+1; next<=sofar;next++){
        if(sofar-next >= 0)
            didItReachI(next,sofar-next);
    } 
}
int main(){
    
    int n;
    cin >> n;
    didItReachI(0,n);
    cout << ans-1 << endl;
    return 0;
}