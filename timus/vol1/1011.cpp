// Boost my confidence
#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
    double p,q;
    cin >> p >> q;
    p = p/100.0;
    q = q/100.0;
    int i = 1;
    while(true){
        int lower = (int) (p*i)+1;
        int upper = (int) (q*i - 1e-9);
        if(lower <= upper){
            cout << i <<endl;
            return 0;
        }
        i++;

    }
    return 0;
}