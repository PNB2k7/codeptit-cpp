#include<iostream>
#include<string>
using namespace std;

void callback(int start, int end, int k, int count, string &s){
    if(count==k) cout<<s<<" ";
    else{
        for(int i=start; i<=end; i++){
            s+=to_string(i);
            callback(i+1,end,k,count+1,s);
            s.resize(s.length()-to_string(i).length());
        }
    }
}

int main(){
    int t; cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s="";
        callback(1,n,k,0,s);
        cout<<endl;
    }
}