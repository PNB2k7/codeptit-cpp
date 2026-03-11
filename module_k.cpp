#include<iostream>
#include<climits>
#define ll long long
using namespace std;

ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

void input(int *a, int n){
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
}

int count(int *a, int n){
    int min = 0;
    for(int i=1; i<n; i++){
        min = gcd(min, abs(a[i]-a[0]));
    }
    int c = 0;
    for(int i=1; i*i <= min; i++){
        if(min%i==0){
            if(i*i == min) c++;
            else c+=2;
        }
    }
    return c;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int *a = new int [n];
        input(a,n);
        cout<<count(a,n)<<endl;
        delete []a;
        a = nullptr;
    }
}