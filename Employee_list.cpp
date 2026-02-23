#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>
using namespace std;

int index_id = 1;

struct date{
    int day, month, year;
};

struct NhanVien{
    string id, name, gender, locate, tax;
    date birth, contact;
};

void input_date(date &t){
    char slash;
    cin>>t.day>>slash>>t.month>>slash>>t.year;
}

void output_date(const date &t){
    cout<<setfill('0')<<setw(2)<<t.day<<'/'
    <<setfill('0')<<setw(2)<<t.month<<'/'
    <<setfill('0')<<setw(4)<<t.year<<" ";
}

int compare_date(const date &n, const date &m){
    if(n.year != m.year) return n.year - m.year;
    if(n.month != m.month) return n.month - m.month;
    return n.day - m.day;
}

void nhap(NhanVien &p){
    stringstream ss;
    ss << setfill('0') << setw(5) << index_id++;
    p.id = ss.str();
    getline(cin>>ws,p.name);
    getline(cin>>ws,p.gender);
    input_date(p.birth);
    getline(cin>>ws,p.locate);
    getline(cin>>ws,p.tax);
    input_date(p.contact);
}

void sapxep(NhanVien list[], int n){
    for(int i=0 ; i < n-1; i++){
        for(int j=0; j< n-i-1; j++){
            if(compare_date(list[j].birth,list[j+1].birth) > 0){
                swap(list[j],list[j+1]);
            }
        }
    }
}

void inds(NhanVien list[], int n){
    for(int i=0; i<n; i++){
        cout<<list[i].id<<" "<<list[i].name<<" "<<list[i].gender<<" ";
        output_date(list[i].birth);
        cout<<list[i].locate<<" "<<list[i].tax<<" ";
        output_date(list[i].contact);
        cout<<endl;
    }
}

int main(){
    struct NhanVien ds[50];
    int N,i;
    cin >> N;
    for(i = 0; i < N; i++) nhap(ds[i]);
    sapxep(ds, N);
    inds(ds, N);
    return 0;
}