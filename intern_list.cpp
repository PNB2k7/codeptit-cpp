#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>
using namespace std;

struct Intern{
    int order;
    string id, name, croom, email, company;
};

void input(Intern l[], int n){
    for(int i=0; i<n; i++){
        l[i].order = i+1;
        cin>>l[i].id;
        getline(cin>>ws,l[i].name);
        cin>>l[i].croom>>l[i].email>>l[i].company;
    }
}

void input_querry(string l[], int n){
    for(int i=0; i<n; i++){
        cin>>l[i];
    }
}

void sort(Intern l[], int n){
    for(int i=0; i<n-1; i++){
        int c=1;
        for(int j=0; j<n-i-1; j++){
            if(l[j].id.compare(l[j+1].id)>0){
                swap(l[j],l[j+1]);
                c=0;
            }
        }
        if(c) break;
    }
}

void output(Intern l[], int n, string s){
    for(int i=0; i<n; i++){
        if(l[i].company == s){
            cout<<l[i].order<<" "<<l[i].id<<" "<<l[i].name<<" "<<l[i].croom<<" "<<l[i].email<<" "<<l[i].company<<endl;
        }
    }
}

int main(){
    int n; cin>>n;
    Intern l[n];
    input(l,n);
    sort(l,n);
    int t; cin>>t;
    string s[t];
    input_querry(s,t);
    for(int i=0; i<t; i++){
        output(l,n,s[i]);
    }
}