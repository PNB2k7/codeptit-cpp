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
    if(l<j) qs(a,l,j);
    if(i<r) qs(a,i,r);
}

int check(int *a, int n, int x){
    int j=0;
    for(int i=1; i<n; i++){
        if(a[i]-a[j] == x) return 1;
        while(a[i]-a[j]>x){
            j++;
        }
    }
    return -1;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n,x; cin>>n>>x;
        int *a = new int [n];
        input(a,n);
        qs(a,0,n-1);
        cout<<check(a,n,x)<<endl;
        delete []a;
    }
}