#include<iostream>
using namespace std;

void input(int *a, int n){
    for(int i=0; i<n; i++) cin>>a[i];
}

void qs(int *a, int l, int r){
    if(l>=r) return;
    int i=l, j=r, mid = a[(l+r)/2];
    while(i<=j){
        while(a[i]<mid) i++;
        while(a[j]>mid) j--;
        if(i<=j){
            swap(a[i],a[j]);
            i++; j--;
        }
    }
    if(i<r) qs(a,i,r);
    if(l<j) qs(a,l,j);
}

void output(int *a, int n){
    int id = 0;
    int *tmp = new int [n];
    for(int i=0; i<n; i+=2) tmp[i] = a[id++];
    for(int i=1; i<n; i+=2) tmp[i] = a[id++];
    for(int i=0; i<n; i++){
        cout<<tmp[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int *a = new int [n];
        input(a,n);
        qs(a,0,n-1);
        output(a,n);
    }
}