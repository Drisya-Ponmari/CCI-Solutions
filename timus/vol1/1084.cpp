// Boost my confidence
#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main(){
    double side,len;
    cin>>side>>len;
    if(len>(side/2)*sqrt(2)){
        cout<<fixed<<setprecision(3)<<side*side;
        return 0;
    }
    if((side/2)>=len){
        cout<<fixed<<setprecision(3)<<len*len*3.1415926;
        return 0;
    }
    double cosx=(side/2)/len;
    double sinx=sqrt(1-cosx*cosx);
    double cosA=2*sinx*cosx;
    double theta=acos(cosA);
    cout<<fixed<<setprecision(3)<<len*len*0.5*theta*4+sqrt(len*len-(side/2)*(side/2))*(side/2)*4;

return 0;
}