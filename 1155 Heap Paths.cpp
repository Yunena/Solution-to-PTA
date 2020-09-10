#include <iostream>
#include <vector>
#include <string>

using namespace std;

string MIN_HEAP = "Min Heap";
string MAX_HEAP = "Max Heap";
string NOT_HEAP = "Not Heap";
bool isMin = false;
bool isMax = false;



void judge(int a, int b){
    if(a<b) isMin = true;
    else if(a>b) isMax = true;
}


void printline(vector<int> list){
    int i = 0;
    for(;i<list.size();i++){
        cout<<list[i];
        if(i!=list.size()-1) cout<<" ";
    }
    cout<<endl;
}

void dfs(vector<int> list, vector<int> vec, int veci){
    if(veci>=vec.size()) ;
    else{
        list.push_back(vec[veci]);
        if(veci*2+1>=vec.size()&&veci*2+2>=vec.size()){
            printline(list);
        }
        else{
            dfs(list,vec,veci*2+2);
            if(veci*2+2<vec.size())
                judge(vec[veci],vec[veci*2+2]);
            dfs(list,vec,veci*2+1);
            if(veci*2+1<vec.size())
                judge(vec[veci],vec[veci*2+1]);
        }
        list.pop_back();
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> vec(n);
    vector<int> list;
    int i = 0;
    for(;i<n;i++){
        cin>>vec[i];
    }
    dfs(list,vec,0);

    if(isMin&&!isMax) cout<<MIN_HEAP;
    else if(isMax&&!isMin) cout<<MAX_HEAP;
    else cout<<NOT_HEAP;

    return 0;
}

