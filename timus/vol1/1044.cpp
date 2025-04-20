// Dp: Solved by myself
#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int t = n/2;
    int max_possible_sum = t*9;
    int dp[max_possible_sum+1][t];
    for(int i = 0; i <= max_possible_sum; i++){
        if(i <= 9) dp[i][0] = 1;
        else dp[i][0] = 0;
    }
    for(int i =0; i <= max_possible_sum; i++){
        for(int j = 1; j < t; j++){
            int temp = 0;
            for(int k = i; k >= max(0,i-9); k--){
                temp += dp[k][j-1];
            }
            dp[i][j] = temp;
        }
    }

    long long ans = 0;
    for(int i = 0; i <= max_possible_sum; i++)
    {
        ans += (dp[i][t-1] * dp[i][t-1]);
    }
    cout << ans << endl;
    return 0;
}