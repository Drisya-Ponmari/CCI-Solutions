
//DP solution is solved. 
#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

bool check(string exp, string curr, int l){
    if(l < 0) return false;
    int i = 0;
    while(i < curr.length()){
        if(exp[l+i] != curr[i]) return false;
        i++;
    }
    return true;
}
int main()
{

    map<char, char> mp = {
        {'i', '1'}, {'j', '1'}, 
        {'a', '2'}, {'b', '2'}, {'c', '2'},
         {'d', '3'}, {'e', '3'}, {'f', '3'}, 
         {'g', '4'}, {'h', '4'}, 
         {'k', '5'}, {'l', '5'},
          {'m', '6'}, {'n', '6'}, 
          {'p', '7'}, {'r', '7'}, {'s', '7'},
           {'t', '8'}, {'u', '8'}, {'v', '8'}, 
           {'w', '9'}, {'x', '9'}, {'y', '9'},
            {'z', '0'}, {'o', '0'}, {'q', '0'}};

    string num;
    int n;
    while (cin >> num)
    {
        if (num == "-1")
            break;
        cin >> n;
        vector<string> numbers;
        vector<string> words;
        while (n--)
        {
            string s;
            cin >> s;
            string a = "";
            for (int i = 0; i < s.length(); i++)
            {
                a += mp[s[i]];
            }
            words.push_back(s);
            numbers.push_back(a);
        }

        int digit_size = num.length();
        // Value at each index represent optimal solution(how many words needed!), till that digit.
        vector<int> dp(digit_size+1, -1); 
        vector<string> ans(digit_size+1, "");
        dp[0] = 0;
        for(int i = 1; i <= digit_size; i++){
            for(int j = 0; j < numbers.size(); j++){
                int start = i - numbers[j].size();
                if(check(num, numbers[j], start) &&
                 dp[start] != -1 && 
                 (dp[i] == -1 || dp[i] > (dp[start]+1))){
                        dp[i] = dp[start]+1;
                        ans[i] = ans[start] +  words[j] + " "; 
                }
            }
        }

        if(dp[digit_size] == -1){
            cout << "No solution." << endl;
        }else{
            string t = ans[digit_size];
            t.erase(t.size()-1, 1);
            cout << t<< endl;
        }
    }
}