#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int an = 0, bn = 0;
    cin>>an;
    vector<double> ae(an),ac(an);
    for(int i = 0;i<an;i++){
        cin>>ae[i]>>ac[i];
    }
    cin>>bn;
    vector<double> be(bn),bc(bn);
    for(int i = 0;i<bn;i++){
        cin>>be[i]>>bc[i];
    }
    int i = 0, j = 0;
    double con = 0;
    vector<double> anse,ansc;
    while(i<an||j<bn){
        if(i<an&&j<bn){
            if(ae[i]==be[j]){
                if(ac[i]+bc[j]==0){
                    i++;
                    j++;
                    continue;
                }
                anse.push_back(ae[i]);
                ansc.push_back(ac[i]+bc[j]);
                //cout<<ae[i]<<" "<<con;
                i++;
                j++;
            }
            else if(ae[i]<be[j]){
                if(bc[j]==0) {j++;continue;}
                con = bc[j];
                anse.push_back(be[j]);
                ansc.push_back(con);
                j++;
            }
            else{
                if(ac[i]==0) {i++;continue;}
                con = ac[i];
                anse.push_back(ae[i]);
                ansc.push_back(con);
                i++;
            }
        }
        else if(i<an){
            if(ac[i]==0) {i++;continue;}
                anse.push_back(ae[i]);
                ansc.push_back(ac[i]);
            i++;
        }
        else if(j<bn){
            if(bc[j]==0) {j++;continue;}
                anse.push_back(be[j]);
                ansc.push_back(bc[j]);
            j++;
        }
    }
    int cnt = 0;
    for(int k = 0;k<anse.size();k++){
        if(ansc[k]==0) ;
        else cnt++;
    }
    cout<<cnt;
    for(int k = 0;k<anse.size();k++){
        if(ansc[k]!=0)
            cout<<" "<<anse[k]<<" "<<ansc[k];
    }
    cout<<endl;
    return 0;


}