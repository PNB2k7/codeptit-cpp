#include<iostream>
#include<string>
using namespace std;

class Student{
    private:
        string id, name, croom, email, field;
    public:
        Student(string id = "", string name = "", string croom = "", string email = "", string field = "")
            : id(id), name(name), croom(croom), email(email), field(field){}
        friend istream& operator >> (istream& in, Student &a);
        friend ostream& operator << (ostream& out, Student &a);
        friend void sort(Student ds[], int N);
        string get_croom() {return croom;}
        string get_id() {return id;}
        string get_field() {return field;}
        void set_field();
};

void Student::set_field(){
    string tmp = id.substr(3,4);
    if(tmp == "DCCN" || tmp == "DCAT"){
        if(croom[0] != 'E') field = tmp;
    }
    else field = tmp;
}

istream& operator >> (istream& in, Student &a){
    in>>a.id;
    getline(in>>ws, a.name);
    in>>a.croom>>a.email;
    a.set_field();
    return in;
}
ostream& operator << (ostream& out, Student &a){
    out<<a.id<<" "<<a.name<<" "<<a.croom<<" "<<a.email<<endl;
    return out;
}
void sort(Student ds[], int N){
    for(int i=0; i<N; i++){
        int c=1;
        for(int j=1; j<N-i; j++){
            if(ds[j].croom.compare(ds[j-1].croom)<0){
                swap(ds[j], ds[j-1]);
                c=0;
            }
            if(ds[j].croom.compare(ds[j-1].croom)==0){
                if(ds[j].id.compare(ds[j-1].id)<0){
                    swap(ds[j], ds[j-1]);
                    c=0;
                }
            }
        }
        if(c) return;
    }
}

int main(){
    int N; cin>>N;
    Student ds[N];
    for(int i=0; i<N; i++) cin>>ds[i];
    int t; cin>>t;
    while(t--){
        string tmp; getline(cin>>ws,tmp);
        string key = "";

        for(int i=0; i<tmp.length(); i++){
            tmp[i] = toupper(tmp[i]);
        }

        if(tmp.find("KE TOAN") != string::npos) key = "DCKT";
        else if(tmp.find("CONG NGHE THONG TIN") != string::npos) key = "DCCN";
        else if(tmp.find("AN TOAN THONG TIN") != string::npos) key = "DCAT";
        else if(tmp.find("VIEN THONG") != string::npos) key = "DCVT";
        else if(tmp.find("DIEN TU") != string::npos) key = "DCDT";

        cout<<"DANH SACH SINH VIEN NGANH "<<tmp<<":\n";
        for(int i=0; i<N; i++){
            if(ds[i].get_field() == key){
                cout<<ds[i];
            }
        }
    }
}