#include<iostream>
#include<string>
using namespace std;

void solve(string s){
    int k=1;
    string tmp=to_string(k++);
    string result = "";
    for(int i=0; i<s.length(); i++){
        if(s[i] =='I'){
            result += tmp;
            tmp = "";
        }
        if(s[i] == 'D') tmp.insert(0,to_string(k++));
        else tmp.append(to_string(k++));
        if(i==s.length()-1){
            result += tmp;
            tmp = "";
        }
    }
    cout<<result<<endl;
}

int main(){
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        solve(s);
    }
}