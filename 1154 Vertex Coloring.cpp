#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

string COLOR = "-coloring";
string NON_COLOR = "No";

string search(vector<vector<int>> vec, vector<int> ver);

int main(){
    int n, m, k;
    cin>>n>>m;
    vector<vector<int>> vec(m,vector<int>(2));
    int i = 0,j = 0;
    for(i=0;i<m;i++){
        cin>>vec[i][0]>>vec[i][1];
    }
    cin>>k;
    vector<int> ver(n);

    for(i=0;i<k;i++){
        for(j=0;j<n;j++){
            cin>>ver[j];
        }
        cout<<search(vec,ver)<<endl;
    }

    return 0;

}

string search(vector<vector<int>> vec, vector<int> ver){
    set<int> set;
    for(int i = 0;i<vec.size();i++){
        if(ver[vec[i][0]]==ver[vec[i][1]]) return NON_COLOR;
    }
    for(int i = 0;i<ver.size();i++){
        set.insert(ver[i]);
    }
    return to_string(set.size())+COLOR;
}