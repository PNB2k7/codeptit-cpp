#include<iostream>
#include<string>
using namespace std;

class Student{
    private:
        string id, name, croom, email;
    public:
        Student(string id = "", string name = "", string croom = "", string email = "")
            : id(id), name(name), croom(croom), email(email){}
        friend istream& operator >> (istream& in, Student &a);
        friend ostream& operator << (ostream& out, Student &a);
        friend void sort(Student ds[], int N);
        string get_croom() {return croom;}
};

istream& operator >> (istream& in, Student &a){
    in>>a.id;
    getline(in>>ws, a.name);
    in>>a.croom>>a.email;
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
    sort(ds,N);
    for(int i=0; i<N; i++) cout<<ds[i];
    int t; cin>>t;
    while(t--){
        string room; cin>>room;
        cout<<"DANH SACH SINH VIEN LOP "<<room<<":\n";
        for(int i=0; i<N; i++){
            if(ds[i].get_croom() == room){
                cout<<ds[i];
            }
        }
    }
}