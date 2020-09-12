#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const int HAS_ANCESTOR = 0;
const int ONE_IS_ANCESTOR = 1;
const int ONE_NOT_FOUND = 2;
const int BOTH_NOT_FOUND = 3;
unordered_map<int, int> map;
void findAncestor(vector<int> inorder, vector<int> preorder, int n1, int n2);
bool isIn(vector<int> inorder, int n);
void printResult(int sig, int ancester, int u, int v);//u is normally seen as ancester if ancester is one of them. 
//if one is not found, ancester is the not found one

int main(){
    int m, n;
    cin>>m>>n;
    vector<int> inorder(n);
    vector<int> preorder(n);
    for(int i = 0;i<n;i++){
        cin>>inorder[i];
        map[inorder[i]] = 1;
    }
    for(int i = 0;i<n;i++){
        cin>>preorder[i];
    }
    for(int i = 0;i<m;i++){
        int n1, n2;
        cin>>n1>>n2;
        findAncestor(inorder, preorder, n1,n2);
    }
    return 0;
}

void findAncestor(vector<int> inorder, vector<int> preorder, int n1, int n2){
    int root = preorder[0];
    int index = 0;
    for(index=0;index<inorder.size();index++){
        if(inorder[index]==root) break;
    }
    bool f1inleft=false,f2inleft=false,f1inright=false,f2inright=false;
    vector<int> left(inorder.begin(),inorder.begin()+index);
    vector<int> right(inorder.begin()+index+1,inorder.end());
    if(n1==root&&n2==root) printResult(ONE_IS_ANCESTOR,n1,n1,n2);
    else if(n1==root){
        if(map.find(n2)!=map.end()){
            printResult(ONE_IS_ANCESTOR, n1, n1, n2);
        }
        else{
            printResult(ONE_NOT_FOUND, n2, n1, n2);
        }
    }
    else if(n2==root){
        if(map.find(n1)!=map.end()){
            printResult(ONE_IS_ANCESTOR,n2,n2,n1);
        }
        else{
            printResult(ONE_NOT_FOUND, n1, n1, n2);
        }
    }
    else{
        if(map.find(n1)==map.end()&&map.find(n2)==map.end()){
            printResult(BOTH_NOT_FOUND,n1,n1,n2);
        }
        else if(map.find(n1)==map.end()){
            printResult(ONE_NOT_FOUND,n1,n1,n2);
        }
        else if(map.find(n2)==map.end()){
            printResult(ONE_NOT_FOUND,n2,n1,n2);
        }
        else{
            f1inleft = isIn(left,n1);
            f2inleft = isIn(left,n2);
            f1inright = isIn(right,n1);
            f2inright = isIn(right,n2);
            if(f1inleft&&f2inright||f1inright&&f2inleft){
                printResult(HAS_ANCESTOR,root,n1,n2);
            }
            else if(f1inleft&&f2inleft){
                vector<int> newpre(preorder.begin()+1,preorder.begin()+index+1);
                findAncestor(left,newpre,n1,n2);
                newpre.clear();
            }
            else if(f2inright&&f1inright){
                vector<int> newpre(preorder.begin()+index+1,preorder.end());
                findAncestor(right,newpre,n1,n2);
                newpre.clear();
            }
        }
    }
    left.clear();
    right.clear();

}

bool isIn(vector<int> inorder, int n){
    if(inorder.size()==0) return false;
    vector<int>::iterator iter;
    iter = inorder.begin();
    for(;iter!=inorder.end();iter++){
        if(*iter==n) return true;
    }
    return false;
}

void printResult(int sig, int ancester, int u, int v){
    switch(sig){
        case HAS_ANCESTOR:
            cout<<"LCA of "<<u<<" and "<<v<<" is "<<ancester<<"."<<endl;
            break;
        case ONE_IS_ANCESTOR:
            cout<<u<<" is an ancestor of "<<v<<"."<<endl;
            break;
        case ONE_NOT_FOUND:
            cout<<"ERROR: "<<ancester<<" is not found."<<endl;
            break;
        case BOTH_NOT_FOUND:
            cout<<"ERROR: "<<u<<" and "<<v<<" are not found."<<endl;
            break;
        default:
            cout<<"?";
    }
}

