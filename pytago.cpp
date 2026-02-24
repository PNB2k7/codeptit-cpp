#include<iostream>
#include<vector>
#include<set>
using namespace std;

void input(long long *p, int n){
    for(int i=0; i<n; i++){
        long long a; cin>>a;
        p[i] = a*a;
    }
}

void qs(long long *a, int l, int r){
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
    if(l<j) qs(a,i,r); 
    if(i<r) qs(a,l,j);
}

bool check(long long *p, int n){
    for(int k = n-1; k>1; k--){
        int l = 0, r = k-1;
        while(l<r){
            if(p[k] == p[l] + p[r]) return true;
            else if (p[k] > p[l] + p[r]) l++;
            else r--;
        }
    }
    return false;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        long long *p = new long long [n];
        input(p,n);
        qs(p,0,n-1);
        cout<<(check(p,n)?"YES":"NO")<<endl;
        delete []p;
    }
}