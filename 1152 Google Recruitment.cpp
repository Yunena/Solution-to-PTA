#include <iostream>
#include <string>

using namespace std;

bool isPrime(int num);

int main(){
    string str;
    int l,k;
    cin>>l>>k;
    cin>>str;
    for(int i = 0;i<=l-k;i++){
        if(isPrime(stoi(str.substr(i,k)))) {cout<<str.substr(i,k)<<endl;return 0;}
    }
    cout<<"404"<<endl;
    return 0;
}

bool isPrime(int num){
    if(num==0||num==1) return false;
    for(int i = 2;i*i<=num;i++){
        if(num%i==0) return false;
    }
    return true;
}