#include<iostream>
#include<string>
using namespace std;

void output(string a){
    for(int i=a.length()-2; i>=0; i--){
        int index = i, last = -1;
        for(int j=i+1; j<a.length(); j++){
            if(a[j]-'0'<a[i]-'0' && a[j]-'0'>last){
                index=j;
                last = a[j]-'0';
            }
        }
        if(index != i){
            swap(a[i],a[index]);
            cout<<a<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}

int main(){
    int t; cin>>t;
    while(t--){
        string a; cin>>a;
        output(a);
    }
}