#include<iostream>
#include<climits>
using namespace std;

void input(int *a, int n){
    for(int i=0; i<n; i++) cin>>a[i];
}

long long multi(int *a, int n){
    long long result = a[0];
    for(int i=0; i<n; i++){
        long long temp = a[i];
        for(int j=i+1; j<n; j++){
            temp *= a[j];
            if(result < temp) result = temp;
        }
    }
    return result;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int *a = new int [n];
        input(a,n);
        cout<<multi(a,n)<<endl;
        delete []a;
    }
}