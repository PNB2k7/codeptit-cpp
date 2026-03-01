#include<iostream>
#include<cmath>
using namespace std;

int input(int *&a, int n, int k){
    int count=0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        if(a[i]<=k) count++;
    }
    return count;
}

void process(int *&a, int n, int k, int w){
    int c=0, l=0, r=0, bad=0, cbad=0;
    while(r<w){
        if(a[r++]>k) bad++;
    }
    cbad = bad;
    for(r=w; r<n; r++){
        if(a[r]>k) bad++;
        if(a[l++]>k) bad--;
        if(bad<cbad) cbad = bad;
    }
    cout<<cbad<<endl;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int *a = new int [n];
        int w = input(a,n,k);
        process(a,n,k,w);
    }
}