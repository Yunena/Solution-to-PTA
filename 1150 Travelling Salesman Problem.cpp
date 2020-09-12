#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

#define INT_MAX  0x7fffffff//?

string TSSC = " (TS simple cycle)";
string TSC = " (TS cycle)";
string NTS = " (Not a TS cycle)";

int count(vector<int> path,vector<vector<int>> ver);

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> ver(n+1,vector<int>(n+1));
    int i = 0;
    while(i<m){
        int x,y;
        cin>>x>>y;
        cin>>ver[x][y];
        ver[y][x]=ver[x][y];
        i++;
    }
    cin>>m;
    i=0;
    //vector<int> length(m);
    int minnum = INT_MAX,index = 0;
    while(i<m){
        int len;
        cin>>len;
        vector<int> path(len);
        for(int j = 0;j<len;j++){
            cin>>path[j];
        }
        cout<<"Path "<<i+1<<": ";
        int length=count(path,ver);
        if(minnum>length){
            minnum = length;
            index=i;
        }
        path.clear();
        i++;
    }
    cout<<"Shortest Dist("<<index+1<<") = "<<minnum<<endl;
    return 0;
}

int count(vector<int> path,vector<vector<int>> ver){
    int sum = 0;
    vector<int> visited(ver.size());
    for(int i = 0;i<path.size();i++){
        if(i==path.size()-1) visited[path[i]]++;
        else if(ver[path[i]][path[i+1]]!=0){
            sum+=ver[path[i]][path[i+1]];
            visited[path[i]]++;
        }
        else{
            cout<<"NA"<<NTS<<endl;
            return INT_MAX;
        }
    }
    //if(visited.size()>1) visited[path[path.size()-1]]++;
    if(path.size()<=1||path[0]!=path[path.size()-1]){
        cout<<sum<<NTS<<endl;
        return INT_MAX;
    }
    for(int i = 1;i<visited.size();i++){
        if(visited[i]>=2&&i==path[0]) continue;
        else if(visited[i]==0){
            cout<<sum<<NTS<<endl;
            return INT_MAX;
        }
        else if(visited[i]>=2){
            cout<<sum<<TSC<<endl;
            return sum;
        }
    }
    cout<<sum<<TSSC<<endl;
    return sum;
}