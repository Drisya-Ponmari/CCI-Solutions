/*
*A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3
steps at a time. Implement a method to count how many possible ways the child can run up the
stairs.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Time limit exceeded 
// Time complexity -> o(2^n)
int recursive(int n){
    if(n<0) return 0;
    if(n==0) return 1;
    return recursive(n-1) + recursive(n-2)+recursive(n-3);
}

// Dynamic programming - Break down to smallter problems 
int dynamic_programming(int n){
    int steps_possible_till[n];
    steps_possible_till[0]=1;
    steps_possible_till[1]=2;
    steps_possible_till[2] = 4;
    for(int i = 3; i <n; i++){
        steps_possible_till[i] = steps_possible_till[i-1]+steps_possible_till[i-2] + steps_possible_till[i-3];
    }
    return steps_possible_till[n-1];
}
int main(){
    int n;
    cin >> n;
    cout << recursive(n) << endl;
    cout << dynamic_programming(n) << endl;
}   