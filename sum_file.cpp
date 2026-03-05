#include<iostream>
#include<fstream>
using namespace std;

void check(string a, long long &sum){
    string s="";
    for(int i=0; i<=a.length(); i++){
        if('0'<=a[i] && a[i]<='9'){
            s.push_back(a[i]);
        }
        else{
            if(s.length()<10&&s!="") sum+=stoi(s);
            s="";
        }
    }
}

int main(){
    long long sum=0;
    ifstream ptr("DATA.in");
    string a;
    while(getline(ptr,a)){
        check(a,sum);
    }
    cout<<sum;
    ptr.close();
}