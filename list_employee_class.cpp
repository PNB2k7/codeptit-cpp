#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>
using namespace std;

int n = 1;

class Date{
    private:
        int day, month, year;
    public:
        Date(int day = 0, int month =0, int year =0) : day(day), month(month), year(year){}
        friend istream& operator >> (istream &in, Date &a);
        friend ostream& operator << (ostream &out, Date &a);
        int compare(Date a);

};
class NhanVien{
    private:
        string id, name, gender, locate, tax;
        Date birth, contact;
    public:
        NhanVien(string id = "", string name = "", string gender = "", Date birth = Date(), string locate = "", string tax = "", Date contact = Date())
            : id(id), name(name), gender(gender), birth(birth), locate(locate), tax(tax), contact(contact) {}
        friend istream& operator >> (istream& in, NhanVien &a);
        friend ostream& operator << (ostream& out, NhanVien &a);
        friend void sapxep(NhanVien ds[], int N);
};

int Date::compare(Date a){
    if(a.year != year) return year < a.year;
    if(a.month != month) return month < a.month;
    return day < a.day;
}
istream& operator >> (istream &in, Date &a){
    char slash;
    in>>a.day>>slash>>a.month>>slash>>a.year;
    return in;
}
ostream& operator << (ostream &out, Date &a){
    out<<setw(2)<<setfill('0')<<a.day<<"/"
    <<setw(2)<<setfill('0')<<a.month<<"/"
    <<a.year;
    return out;
}
istream& operator >> (istream &in, NhanVien &a){
    string tmp = to_string(n++);
    while(tmp.length() != 5) tmp.insert(tmp.begin(),'0');
    a.id = tmp;
    getline(in>>ws,a.name);
    in>>a.gender>>a.birth;
    getline(in>>ws,a.locate);
    in>>a.tax>>a.contact;
    return in;
}
ostream& operator << (ostream &out, NhanVien &a){
    out<<a.id<<" "<<a.name<<" "<<a.gender<<" "<<a.birth<<" "<<a.locate<<" "<<a.tax<<" "<<a.contact<<endl;
    return out;
}
void sapxep(NhanVien ds[], int N){
    for(int i=0; i<N; i++){
        int ok = 1;
        for(int j=1; j<N-i; j++){
            if(ds[j].birth.compare(ds[j-1].birth)){
                swap(ds[j],ds[j-1]);
                ok=0;
            }
        }
        if(ok) return;
    }
}

int main(){
    NhanVien ds[50];
    int N,i;
    cin >> N;
    for(i=0;i<N;i++) cin >> ds[i];
    sapxep(ds, N);
    for(i=0;i<N;i++) cout << ds[i];
    return 0;
}