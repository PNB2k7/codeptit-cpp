#include<iostream>
using namespace std;

void qs(int *a, int l, int r){
    if(l>=r) return;
    int mid = a[(l+r)/2], i=l, j=r;
    while(i<=j){
        while(a[i]<mid) i++;
        while(a[j]>mid) j--;
        if(i<=j){
            swap(a[i],a[j]);
            i++; j--;
        }
    }
    qs(a,i,r); qs(a,l,j);
}

void input(int *a, int n){
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    qs(a,0,n-1);
}

void output(int *a, int n){
    int i=0, j=n-1, c=1;
    while(i<=j){
        if(c){
            cout<<a[j--]<<" ";
            c=0;
        }
        else{
            cout<<a[i++]<<" ";
            c=1;
        }
    }
    cout<<endl;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int *a = new int [n];
        input(a,n);
        output(a,n);
    }
}