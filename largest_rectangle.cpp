#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

void initialize(int **&a, int n, int m){
    a = new int*[n];
    for(int i=0;i<n;i++)
        a[i] = new int[m];
}

void freeMem(int **&a, int n){
    for(int i=0;i<n;i++) delete[] a[i];
    delete[] a;
}

void input(int **a, int n, int m){
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> a[i][j];
}

void process(int **a, int n, int m){
    int **b;
    initialize(b,n,m);

    // Tính height
    for(int j=0;j<m;j++){
        b[0][j] = a[0][j];
        for(int i=1;i<n;i++){
            if(a[i][j])
                b[i][j] = b[i-1][j] + 1;
            else
                b[i][j] = 0;
        }
    }

    int ans = 0;

    for(int i=0;i<n;i++){
        sort(b[i], b[i]+m, greater<int>());

        for(int k=0;k<m;k++){
            ans = max(ans, b[i][k]*(k+1));
        }
    }

    cout << ans << endl;
    freeMem(b,n);
}

int main(){
    int t; cin >> t;
    while(t--){
        int n,m; 
        cin >> n >> m;

        int **a;
        initialize(a,n,m);
        input(a,n,m);
        process(a,n,m);
        freeMem(a,n);
    }
}