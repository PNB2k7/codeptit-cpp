#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Date{
    private:
        int day,month,year;
    public:
        Date(int d =0, int m = 0, int y = 0){
            day = d;
            month = m;
            year = y;
        }
        void input_day(){
            char slash;
            cin>>day>>slash>>month>>slash>>year;
        }
        void output_day(){
            cout<<setfill('0')<<setw(2)<<day<<"/"
            <<setfill('0')<<setw(2)<<month<<"/"
            <<year<<" ";
        }
};

class SinhVien{
    private:
        string id, name, croom;
        Date birth;
        float gpa;
    public:
        SinhVien(string i = "B20DCCN001", string n = "", string c = "", Date b = Date(), float g = 0)
            :id(i),name(n),croom(c),birth(b),gpa(g){}
        void nhap(){
            getline(cin>>ws,name);
            cin>>croom;
            birth.input_day();
            cin>>gpa;
        }
        void xuat(){
            cout<<id<<" "<<name<<" "<<croom<<" ";
            birth.output_day();
            cout<<fixed<<setprecision(2)<<gpa;
        }
        friend istream& operator >> (istream &in, SinhVien &a){
            a.nhap();
            return in;
        }

        friend ostream& operator << (ostream &out, SinhVien a){
            a.xuat();
            return out;
        }
};

int main(){
    SinhVien a;
    cin >> a;
    cout << a;
    return 0;
}