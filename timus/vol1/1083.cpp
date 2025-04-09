// Boost my confidence
#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
   int a;
   cin >> a;
   char c;
   // cin >> skips white spaces. so use cin.get()
   cin.get(c);
   int k=0;
   while(cin.get(c)){
    if(c != '!') break;
    k++;
   }
   long ans = 1;
   while(a > 0){
    ans *= a;
    a -= k;
   }

   cout << ans << endl;
   return 0;
}