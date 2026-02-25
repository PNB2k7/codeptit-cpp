#include<iostream>
#include<string>
#include<map>
using namespace std;

struct cmp{
    bool operator()(const string &a, const string &b)const{
        if(a+b>b+a) return true;
        if(a+b<b+a) return false;
        return a<b;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        map<string,int,cmp> mp;
        for(int i=0; i<n; i++){
            string a; cin>>a;
            mp[a]++;
        }
        for(map<string,int>::iterator it = mp.begin(); it != mp.end(); it++){
            for(int i=0; i<(*it).second; i++){
                cout<<(*it).first;
            }
        }
        cout<<endl;
    }
}