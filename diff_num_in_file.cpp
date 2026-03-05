#include<iostream>
#include<map>
#include<fstream>
using namespace std;

void check(string a, map<int,int> &mp){
    int s=-1;
    for(int i=0; i<=a.length(); i++){
        if('0'<=a[i] && a[i]<='9'){
            if(s==-1) s=0;
            s = s*10 + (a[i]-'0');    
        }
        else{
            if(s!=-1) mp[s]++;
            s=-1;
        }
    }
}

int main(){
    ifstream ptr("DATA.in");
    string a;
    map<int,int> mp;
    while(getline(ptr,a)){
        check(a,mp);
    }
    for(pair<int,int> x:mp){
        cout<<x.first<<" "<<x.second<<endl;
    }
}