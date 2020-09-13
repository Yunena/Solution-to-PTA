#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

/*bool cmp(const vector<int> &a, const vector<int> &b){
    if(a[0]!=b[0]) return a[0]<b[0];
    else return a[1]<b[1];
}*/

int main(){
    int n,m;
    cin>>n>>m;
    map<int,set<int>> _map;
    int i,j,k,p;
    for(i=0;i<n;i++){
        int x, y;
        cin>>x>>y;
        if(x>y){
            int t = x;
            x = y;
            y = t;
        }
        if(_map.find(x)!=_map.end()){
            set<int> _vec=_map[x];
            _vec.insert(y);
            _map[x] = _vec;
        }
        else{
            set<int> _vec;
            _vec.insert(y);
            _map[x] = _vec;
        }
    }
    for(i=0;i<m;i++){
        int K;
        cin>>K;
        vector<int> list(K);
        for(j=0;j<K;j++){
            cin>>list[j];
        }
        sort(list.begin(),list.end());
        j=0;
        k=0;
        p=0;
        bool flag = true;
        while(j<K&&flag){
            if(_map.find(list[j])!=_map.end()){
                k = j+1;
                set<int> _set(_map[list[j]]);
                while(k<K){
                    if(_set.find(list[k])!=_set.end()){
                        flag = false;
                        break;
                    }
                    k++;
                }
            }
            j++;
        }
        if(flag) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}