#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
    int a, b;
    cin>>a>>b;
    int c = a+b;
    string sign="", res="";
    if(c==0) {cout<<"0"<<endl;return 0;}
    //cout<<a<<" "<<b<<" "<<c<<endl;
    if(c<0){
        sign = "-";
        c = -c;
    }
    int cnt = 0, mod = 10;
    //cout<<"???: "<<c<<endl;
    while(c>0){
        string s = to_string(c%mod);
        //cout<<res<<" "<<s<<endl;
        cnt++;
        res = s+res;
        c/=mod;
        if(c!=0&&cnt==3){
            cnt=0;
            res = ","+res;
        }
        
    }
    res = sign+res;
    cout<<res<<endl;

    return 0;

}