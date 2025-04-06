/**recursion - TLE*/
#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define ll unsigned long long

string ans;

string check(string exp, int start, string curr)
{
    if(curr.length() > exp.length()) return "";
    int i = 0;
    while (i < curr.length())
    {
        if (curr[i] != exp[start + i])
            return "";
        i++;
    }
    return curr;
}
void better(string exp,
            vector<string> &numbers,
            vector<string> &words,
            vector<int> &res,
            int index, string curr)
{
    if (curr.length() > exp.length()) return;
    if (curr == exp)
    {
        string temp = "";
        for (int i = 0; i < res.size(); i++)
        {
            temp += words[res[i]] + " ";
        }
        temp.pop_back();
        if (ans.empty() || ans.length() > temp.length())
        {
            ans = temp;
        }
        return;
    }
    if(index >= exp.length()) return;
    for (int i = 0; i < numbers.size(); i++)
    {
        if (check(exp, index, numbers[i]) != "")
        {
            res.push_back(i);
            better(exp, numbers, words, res, index + numbers[i].size(), curr + numbers[i]);
            res.pop_back();
        }
    }
    return;
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
        vector<int> res;
        better(num, numbers, words, res, 0, "");
        if (ans.empty())
        {
            cout << "No solution." << endl;
        }
        else
            cout << ans << endl;
        ans = "";
    }
}