#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

struct SinhVien{
    string id, name, croom;
    float d1,d2,d3;
};

void nhap(SinhVien &p){
    getline(cin>>ws,p.id);
    getline(cin>>ws,p.name);
    getline(cin>>ws,p.croom);
    cin>>p.d1>>p.d2>>p.d3;
}

void sap_xep(SinhVien *l, int n){
    for(int i=0; i<n-1; i++){
        int c=1;
        for(int j=0; j<n-i-1; j++){
            if(l[j].name.compare(l[j+1].name)>0){
                swap(l[j],l[j+1]);
                c=0;
            }
        }
        if(c) break;
    }
}

void in_ds(SinhVien l[], int n){
    for(int i=0; i<n; i++){
        cout<<i+1<<" "<<l[i].id<<" "<<l[i].name<<" "<<l[i].croom<<" "
        <<fixed<<setprecision(1)<<l[i].d1<<" "<<l[i].d2<<" "<<l[i].d3<<endl;
    }
}

int main(){
    int n;
    cin >> n;
    struct SinhVien *ds = new SinhVien[n];
    for(int i = 0; i < n; i++) {
    	nhap(ds[i]);
	}
	sap_xep(ds, n);
    in_ds(ds,n);
    return 0;
}