#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<sstream>
using namespace std;

class Date{
    private:
        int day, month, year;
    public:
        Date(int day = 0, int month = 0, int year = 0)
            : day(day), month(month), year(year){}
        void input(istream &in);
        void output(ostream &out) const;
};

class SinhVien{
    private:
        string id, name, croom;
        Date birth;
        float GPA;
    public:
        SinhVien(string id="", string name = "", string croom = "", Date birth = Date(), float GPA=0);
        void input(istream& in);
        void output(ostream& out) const;
        friend istream& operator >> (istream& in, SinhVien &a);
        friend ostream& operator << (ostream& out, const SinhVien &a);
        void standard();
};

int main(){
    SinhVien a;
    cin >> a;
    cout << a;
    return 0;
}

void Date::input(istream &in){
    char slash;
    in>>ws>>day>>slash>>month>>slash>>year;
}

void Date::output(ostream &out) const{
    out<<setw(2)<<setfill('0')<<day<<"/"
    <<setw(2)<<setfill('0')<<month<<"/"
    <<year<<" ";
}

SinhVien::SinhVien(string id, string name, string croom, Date birth, float GPA)
    : id(id), name(name), croom(croom), birth(birth), GPA(GPA){}

void SinhVien::standard(){
    stringstream ss(name);
    string res="",word="";
    while(ss>>word){
        word[0] = toupper (word[0]);
        for(int i=1; i<word.length(); i++){
            word[i] = tolower(word[i]);
        }
        res += word + " ";
    }
    name = res;
}

void SinhVien::input(istream &in){
    id = "B20DCCN001";
    getline(in>>ws, name);
    standard();
    getline(in>>ws, croom);
    birth.input(in);
    in>>GPA;
}

void SinhVien::output(ostream &out) const{
    out<<id<<" "<<name<<" "<<croom<<" ";
    birth.output(out);
    out<<fixed<<setprecision(2)<<GPA;
}

istream& operator >> (istream &in, SinhVien &a){
    a.input(in);
    return in;
}

ostream& operator << (ostream &out, const SinhVien &a){
    a.output(out);
    return out;
}