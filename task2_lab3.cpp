#include<iostream>
#include <string>
using namespace std;

struct Student{

    string name;
    int roll_no;
    float marks;
};

void update(Student* p){
    cout<<"Enter Name you want to update :";
    getline(cin,p->name);
    cout<<"Enter roll no you want to update :";
    cin>>p->roll_no; 
    cout<<"Enter marks you want to update :";
    cin>>p->marks;
}
int main(){

    Student s1;
    Student* p=&s1;

    p->name="Bilal Ahmed";
    p->roll_no=573512;
    p->marks=98.5;
    cout<<"\nBefore update The Student name is : "<<p->name<<" with roll no : "<<p->roll_no<<" having marks "<<p->marks<<endl;

    update(p);

    cout<<"\nAfter update The Student name is : "<<p->name<<" with roll no : "<<p->roll_no<<" having marks "<<p->marks<<endl;

    return 0;
}