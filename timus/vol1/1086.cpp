// Boost my confidence
#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
    int a;
    cin >> a;

    int m = 2 * 1e5;
    bool flag = true;
    vector<int> prime;
    prime.push_back(2);
    prime.push_back(3);
    for(int i = 4; i < m; i++){
        flag = true;
        for(int j = 2; j*j <= i && flag; j++){
            if(i%j == 0){
                flag = false;
            }
        }
        if(flag)
            prime.push_back(i);
    }
    while (a--)
    {
       int k;
       cin >> k;
       cout << prime[k-1] << endl;
    }
    return 0;
}