#include<bits/stdc++.h>
#include<fstream>
using namespace std;

class Student{
    public:
    int roll;
    char div;
    string name;
    Student(){
        roll = 0;
        div = ' ';
        name = " ";
    }
};

void create(){
    Student st;
    ofstream f;
    f.open("st2.txt", ios::out);
    char c;
    do{
        cout << "Enter name:";
        cin >> st.name;
        cout<< "Enter roll:";
        cin >> st.roll;
        cout << "enter div:";
        cin>>st.div;
        cout << "continue? ";
        cin >> c;
        f.write((char*)&st, sizeof(st));
    }
    while(c == 'y');f.close();
}
void display(){
    Student st;
    ifstream f;
    f.open("st2.txt",ios::in);
    while(f.read((char*)&st, sizeof(st))){
        cout << st.name << endl << st.div<< endl << st.roll << endl;
    }
    f.close();

}

int main(){
    create();
    display();
    return 0;
}