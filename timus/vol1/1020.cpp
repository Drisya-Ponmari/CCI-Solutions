
#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

double dist(double x , double y, double a, double b){
    double first = (x-a) * (x-a);
    double second = (y-b) * (y-b);
    return sqrt(first + second);
}
int main(){
    int n;
    double r;
    cin >> n >> r;
    vector<vector<double>> ed;
    double x,y;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        vector<double> temp = {x,y};
        ed.push_back(temp);
    }

    double ans = 0.00;
    for(int i = 1; i < n; i++){
        ans += dist(ed[i][0], ed[i][1], ed[i-1][0],ed[i-1][1]);
    }

    //connect the last one
    ans += dist(ed[0][0], ed[0][1], ed[n-1][0], ed[n-1][1]);
    //Exterior angle
    ans += (2*3.14*r);
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}