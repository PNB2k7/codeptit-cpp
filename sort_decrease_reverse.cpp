#include<iostream>
#include<string>
#include<map>
using namespace std;

bool check_reverse(const string &s){
    if(s.length()<2) return false;
    int i=0, j=s.length()-1;
    while(i<=j){
        if(s[i] != s[j]) return false;
        i++; j--;
    }
    return true;
}

struct cmp{
    bool operator()(const string &a, const string &b) const {
        if(a.length() != b.length()) return a.length() < b.length();
        return a < b;
    }
};

int main(){
    string s;
    map<string,int,cmp> mp;
    while(cin>>s){
        if(check_reverse(s)) mp[s]++;
    }
    for(map<string,int>::reverse_iterator it = mp.rbegin(); it != mp.rend(); it++){
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }
}