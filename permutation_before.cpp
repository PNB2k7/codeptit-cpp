#include<iostream>
#include<algorithm>
using namespace std;

void input(int *a, int n){
    for(int i=0; i<n; i++) cin>>a[i];
}

void output(int *a, int n){
    int i = n-2;
    while(a[i]<=a[i+1] && i>=0) i--;
    if(i==0){
        for(int i=n-1; i>=0; i--) cout<<a[i]<<" ";
        cout<<endl;
        return;
    }
    int min = n-1;
    for(int j=n-2; j>i; j--){
        if(a[min]<a[j] && a[j]<a[i]) min = j;
    }
    swap(a[i],a[min]);
    reverse(a+i+1, a+n);
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
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
        delete[] a;
    }
}