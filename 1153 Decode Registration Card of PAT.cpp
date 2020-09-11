#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef struct PTACARD{
    string str;
    string level;
    string test_site;
    string year;
    string month;
    string date;
    string testee;
}Card;

typedef struct CARDPAIR{
    Card card;
    int grade;
    
    
}CardPair;

Card cardGenerate(string str);
//void classify(int type, string term);
CardPair cardpairGenerate(string str, int grade);
bool cmpCardPair(const CardPair &a, const CardPair &b);
void type_one(string term, vector<CardPair> cardpairs);
void type_two(string term, vector<CardPair> cardpairs);
void type_thr(string term, vector<CardPair> cardpairs);

CardPair cardpairGenerate(string str, int grade){
    CardPair cardpair;
    cardpair.card = cardGenerate(str);
    cardpair.grade = grade;
    return cardpair;

}

Card cardGenerate(string str){
    Card card;
    card.str = str;
    //cout<<str<<" ";
    card.level = str.substr(0,1);
    //cout<<card.level<<" ";
    card.test_site = str.substr(1,3);
    //cout<<card.test_site<<" ";
    card.year = str.substr(4,2);
    //cout<<card.year<<" ";
    card.month = str.substr(6,2);
   //cout<<card.month<<" ";
    card.date = str.substr(8,2);
    //cout<<card.date<<" ";
    card.testee = str.substr(10,3);
    //cout<<card.testee<<" "<<endl;
    return card;
}

bool cmpCardPair(const CardPair &a, const CardPair &c){
        if(a.grade!=c.grade) return a.grade>c.grade;
        else if(a.card.test_site!=c.card.test_site) return a.card.test_site<c.card.test_site;
        else if(a.card.year!=c.card.year) return a.card.year<c.card.year;
        else if(a.card.month!=c.card.month) return a.card.month<c.card.month;
        else if(a.card.date!=c.card.date) return a.card.date<c.card.date;
        else return a.card.testee<c.card.testee;
}

int main(){
    string str;
    int num;
    int n, m;
    cin>>n>>m;
    vector<Card> cards(n);
    vector<int> grades(n);
    vector<CardPair> cardpairs(n);
    //map<Card, int> maps;
    int i = 0;
    for(i = 0;i<n;i++){
        cin>>str>>num;
        cards[i] = cardGenerate(str);
        grades[i] = num;
        cardpairs[i] = cardpairGenerate(str,num);
        //cout<<endl<<"cardpair :";
    }
    int type;
    string term;
    for(i=0;i<m;i++){
        cin>>type>>term;
        cout<<"Case "<<i+1<<": "<<type<<" "<<term<<endl;
        switch(type){
        case 1:
            type_one(term, cardpairs);
            break;
        case 2:
            type_two(term, cardpairs);
            break;
        case 3:
            type_thr(term, cardpairs);
            break;
        }

    }

    return 0;
}

void type_one(string term, vector<CardPair> cardpairs){
    string c = term.substr(0,1);
    vector<CardPair> vec;
    for(int i = 0;i<cardpairs.size();i++){
        if(cardpairs[i].card.level==c){
            vec.push_back(cardpairs[i]);
        }
    }
    sort(vec.begin(),vec.end(),cmpCardPair);
    for(int i = 0;i<vec.size();i++){
        cout<<vec[i].card.str<<" "<<vec[i].grade<<endl;
    }
    if(vec.size()==0) cout<<"NA"<<endl;
}

void type_two(string term, vector<CardPair> cardpairs){
    int count = 0, sum = 0;
    for(int i = 0;i<cardpairs.size();i++){
        if(cardpairs[i].card.test_site==term){
            count++;
            sum+=cardpairs[i].grade;
        }
    }
    if(count>0)
        cout<<count<<" "<<sum<<endl;
    else
    {
        cout<<"NA"<<endl;
    }
    
}

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
        if(a.second!=b.second) return a.second > b.second;
        else return a.first<b.first;
}

void type_thr(string term, vector<CardPair> cardpairs){
    unordered_map<string, int> m;
    for(int i = 0;i<cardpairs.size();i++){
        if(cardpairs[i].card.str.substr(4,6)==term){
            if(m.find(cardpairs[i].card.test_site)!=m.end()){
                int cnt = m[cardpairs[i].card.test_site];
                m[cardpairs[i].card.test_site] = cnt+1;
            }
            else{
                m[cardpairs[i].card.test_site] = 1;
            }
        }
    }
    //map<string, int>::iterator iter;
    //iter = m.begin();
    vector<pair<string, int>> vec(m.begin(), m.end());
    sort(vec.begin(),vec.end(),cmp);
    if(vec.size()==0) cout<<"NA"<<endl;
    else{
        for(int i = 0;i<vec.size();i++){
            cout<<vec[i].first<<" "<<vec[i].second<<endl;
        }
    }
}



