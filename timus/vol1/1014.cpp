/**
 * 
 * Accepted
 *  1. Each digit is in between 2 and 9
 *  2. It should be sorted
 *  3. If we are able to multiply, say 2 consecutively replace with 4
 *  4. use long long for answer
 *  5. Start dividing by 9, why this leads to lesser number of digits.
 */

#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
  int n; 
  cin >> n;
  if(n==0){
    cout << 10 << endl;
    return 0;
  }else if(n==1){
    cout << 1 << endl;
    return 0;
  }
  int k = 9;
  vector<int> digits;
  int count = 0;
  while(n > 1 && k > 1){
    if(n%k != 0){
        k--;
        continue;
    }
    n = n/k;
    if(count != 0 && digits[count-1]*k <= 9){
        digits[count-1] = digits[count-1]*k;
    }else{
        digits.push_back(k);
        count++;
    }
  }
  if(n > 1){
    cout << -1 << endl;
    return 0;
  }
  sort(digits.begin(), digits.end());
 long long ans=0;
  for(int digit : digits){
    ans = ans * 10 + digit;
  }
  cout << ans << endl;
  return 0;
}