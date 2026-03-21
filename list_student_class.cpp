#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>
using namespace std;

int n=1;

string standard (string &s);

class Date{
    private:
        int day, month, year;
    public:
        Date(int day = 0, int month = 0, int year = 0) : day(day), month(month), year(year) {}
        friend istream& operator >> (istream &in, Date &a);
        friend ostream& operator << (ostream &out, Date &a);
};

class SinhVien{
    private:
        string id,name,croom;
        Date birth;
        float gpa;
    public:
        SinhVien(string id = "", string name = "", string croom = "", Date birth = Date(), float gpa = 0)
            : id(id), name(name), croom(croom), birth(birth), gpa(gpa) {}
        friend istream& operator >> (istream& in, SinhVien &a);
        friend ostream& operator << (ostream& out, SinhVien &a);
        friend void sapxep(SinhVien ds[], int N);
};

string standard (string &s){
    stringstream ss(s);
    string word = "", res = "";
    while(ss>>word){
        if(res != "") res+= " ";
        word[0] = toupper(word[0]);
        for(int i=1; i<word.length(); i++) word[i] = tolower(word[i]);
        res += word;
    }
    return res;
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

istream& operator >> (istream &in, SinhVien &a){
    string tmp = to_string(n++);
    while(tmp.length()!=3) tmp.insert(tmp.begin(),'0');
    a.id = "B20DCCN" + tmp;
    getline(in>>ws,tmp); a.name = standard(tmp);
    in>>a.croom>>a.birth>>a.gpa;
    return in;
}

ostream& operator <<(ostream &out, SinhVien &a){
    out<<a.id<<" "<<a.name<<" "<<a.croom<<" "<<a.birth<<" "<<fixed<<setprecision(2)<<a.gpa<<endl;
    return out;
}

void sapxep(SinhVien ds[], int N){
    for(int i=0; i<N-1; i++){
        int ok = 1;
        for(int j=1; j<N-i; j++){
            if(ds[j].gpa>ds[j-1].gpa) {
                swap(ds[j],ds[j-1]);
                ok=0;
            }
            if(ok) return;
        }
    }
}

int main(){
    SinhVien ds[50];
    int N, i;
    cin >> N;
    for(i=0;i<N;i++){
        cin >> ds[i];
    }
    sapxep(ds, N);
    for(i=0;i<N;i++){
        cout << ds[i];
    }
    return 0;
}