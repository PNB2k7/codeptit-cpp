#include<iostream>
#include<set>
#include<fstream>
#include<sstream>
using namespace std;

void check(string s, set<string> &st){
    stringstream ss(s);
    string word;
    while(ss>>word){
        for(int i=0; i<word.length(); i++){
            word[i]=tolower(word[i]);
        }
        st.insert(word);
    }
}

int main(){
    string s;
    ifstream ptr("VANBAN.in");
    set<string> st;
    while(getline(ptr,s)){
        check(s,st);
    }
    for(string x: st){
        cout<<x<<endl;
    }
}