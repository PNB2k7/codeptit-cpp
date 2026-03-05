#include<iostream>
#include<fstream>
#include<string>
#include<set>
#include<sstream>
using namespace std;

void lower(string &a){
    for(int i=0; i<a.length(); i++) a[i] = tolower(a[i]);
}

void load(set<string> &st, ifstream &ptr){
    string a;
    while(getline(ptr,a)){
        string word;
        stringstream ss(a);
        while(ss>>word) {
            lower(word);
            st.insert(word);
        } 
    }
}

void con_dis_juction(set<string> &st1, set<string> &st2){
    set<string> con,dis;
    for(string x:st1){
        con.insert(x);
        if(st2.find(x)!=st2.end()) dis.insert(x);
    }
    for(string x:st2) con.insert(x);

    for(string x:con) cout<<x<<" ";
    cout<<endl;
    for(string x:dis) cout<<x<<" ";
}

int main(){
    ifstream ptr1("DATA1.in"), ptr2("DATA2.in");
    set <string> st1, st2;
    load(st1,ptr1);
    load(st2,ptr2); 
    con_dis_juction(st1,st2);
    ptr1.close();
    ptr2.close();
}