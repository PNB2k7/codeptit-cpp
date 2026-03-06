#include<iostream>
using namespace std;

long long multi(long long a, long long b, long long c){
    long long temp = 0;
    while(b != 0){
        if(b%2) {
            temp = (temp%c) + (a%c);
            b--;
        }
        a = (a%c) *(2%c)%c;
        b/=2;
    }
    return (temp%c)%c;
}

int main(){
    int t; cin>>t;
    while(t--){
        long long a,b,c;
        cin>>a>>b>>c;
        cout<<multi(a,b,c)<<endl;
    }
}