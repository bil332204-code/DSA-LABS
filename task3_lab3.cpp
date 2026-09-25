#include<iostream>
#include <string>
using namespace std;

struct Student{

    string name;
    int roll_no;
    float marks;

};
int main(){

    Student* p=new Student();
    if(p!=nullptr){
        cout<<"Enter Student name : ";
        getline(cin,p->name);
        cout<<"\nEnter Student roll no : ";
        cin>>p->roll_no;
        cout<<"\nEnter Student marks : ";
        cin>>p->marks;
    }    
    cout<<"\nThe Student name is : "<<p->name<<" with roll no : "<<p->roll_no<<" having marks "<<p->marks<<endl;

    delete p;
    p=nullptr;
}