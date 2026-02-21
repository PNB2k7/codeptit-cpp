#include<iostream>
#include<map>
#include<string>
using namespace std;

void output(string &s){
    map<char,int> mp;
    for(int i=0; i<s.length(); i++){
        mp[s[i]]++;
    }
    long long sum = 0;
    for(int i=0; i<=9; i++){
        if(mp.count(i+'0') != 0) {
            sum += i*mp[i+'0'];
            mp.erase(i+'0');
        }
    }
    for(pair<char,int> x:mp){
        for(int i=0; i<x.second; i++){
            cout<<x.first;
        }
    }
    cout<<sum<<endl;
}

int main(){
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        output(s);
    }
}