#include<iostream>
using namespace std;

int process(int *a, int n, int k){
    int cbad=0, bad=0;
    for(int i=0; i<k; i++){
        if(a[i]) bad++;
    }
    cbad=bad;
    for(int i=k; i<n; i++){
        if(a[i-k]) bad--;
        if(a[i]) bad++;
        if(cbad>bad) cbad=bad;
    }
    return cbad;
}

int main(){
    int n, k, b;
    cin>>n>>k>>b;
    int *a = new int [n]();
    for(int i=0; i<b; i++){
        int tmp; cin>>tmp;
        a[tmp-1]=1;
    }
    cout<<process(a, n, k);
}