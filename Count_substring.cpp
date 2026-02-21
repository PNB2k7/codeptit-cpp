#include<iostream>
#include<string>
#include<map>
using namespace std;

int count(string a, int n) {
    int c = 0, l = 0, r = 0;
    map<char, int> mp;

    for (r = 0; r < a.length(); r++) {
        mp[a[r]]++;

        while (mp.size() > n) {
            mp[a[l]]--;
            if (mp[a[l]] == 0) mp.erase(a[l]);
            l++;
        }

        c += (r - l + 1);   
    }
    return c;
}

int main(){
    int t; cin>>t;
    while(t--){
        string a; cin>>a;
        int n; cin>>n;
        cout<<count(a,n) - count(a,n-1)<<endl;
    }
}