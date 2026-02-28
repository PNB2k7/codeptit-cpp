#include<iostream>
using namespace std;

void input(int **a, int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
        }
    }
}

void free(int **&a, int n){
    for(int i=0; i<n; i++){
        delete[] a[i];
    }
    delete[] a;
    a = nullptr;
}

void free(int *&a){
    delete[] a;
    a = nullptr;
}


int process(int *b, int *c, int n){
    int rowMax = 0, colMax = 0;
    int total = 0;
    for(int i=0; i<n; i++){
        if(b[i] > rowMax) rowMax = b[i];
        if(c[i] > colMax) colMax = c[i];
        total += b[i];   // tổng ma trận = tổng các hàng
    }
    int target = (rowMax > colMax) ? rowMax : colMax;
    return n * target - total;
}


int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int **a = new int *[n];
        for(int i=0; i<n; i++){
            a[i] = new int [n];
        }
        input(a,n,n);
        int *b = new int [n](), *c = new int [n]();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                b[i]+=a[i][j];
                c[j]+=a[i][j];
            }
        }
        cout<<process(b,c,n)<<endl;
        free(a,n); free(b); free(c);
    }
}
