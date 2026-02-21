#include <iostream>
#include <string>
using namespace std;

int ok;

void callback(int n, string a = ""){
    if(a.length() == n){
        cout<<a<<endl;
        return;
    }
    for(int i=0; i<2; i++){
        a.push_back(i+'0');
        callback(n,a);
        a.pop_back();
    }
}

void sinh(int n, int a[]){
    int i=n;
    while(i>=1 && a[i] == 1){
        a[i] = 0;
        --i;
    }
    if(i==0){
        ok = 0;
    }
    else{
        a[i] = 1;
    }
}

int main() {
    int a[100] ={0};
    int n; cin>>n;
    sinh(n,a);
}