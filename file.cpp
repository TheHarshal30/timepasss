#include<iostream>
#include<fstream>
using namespace std;

class student{
    public:
    int roll;
    char  name[10];
    char div;

    void create(){
        char c;
        student st;
        ofstream f;
        f.open("st.txt",ios::out);
        do{
            cout<<"Enter roll"<<endl;
            cin>>st.roll;
            cout<<"Enter name"<<endl;
            cin>>st.name;
            cout<<"Enter div"<<endl;
            cin>>st.div;
            f.write((char*)&st, sizeof(st));
            cout << "Do you want to enter more students? (y/n): ";
            cin >> c;
        }
        while(c=='y');
            f.close();
    }
     void display(){
        ifstream f;
        student st;
        f.open("st.txt",ios::in);
        while(f.read((char *)&st,sizeof(st)))
                cout<< st.roll <<"\t"<<st.name<<"\t"<<st.div<<"\t";
        f.close();    


     }
};

int main(){
    student st;
    st.create();
    st.display();

    return 0;       
}