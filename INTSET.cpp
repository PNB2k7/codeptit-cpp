#include<iostream>
#include<set>
#include<fstream>
using namespace std;

int main(){
    ifstream ptr("DATA.in");
    int n,m;
    ptr>>n>>m;
    int a; set<int> st1,st2;
    for(int i=0; i<n; i++){
        ptr>>a;
        st1.insert(a);
    }
    for(int i=0; i<m; i++){
        ptr>>a;
        if(st1.find(a)!=st1.end()) st2.insert(a);
    }
    for(int x:st2) cout<<x<<" ";
}