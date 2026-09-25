#include<iostream>
#include <string>
using namespace std;

struct Student{

    string name;
    int roll_no;
    double marks;

    void display() const{
        cout<<"\nThe Student name is : "<<name<<" with roll no : "<<roll_no<<" having marks "<<marks;
    }

};
int main(){

    Student s1;
    cout<<"Enter Student Name : ";
    getline(cin, s1.name);
    cout<<"\nEnter Student roll no : ";
    cin>>s1.roll_no;
    cout<<"\nEnter Student marks : ";
    cin>>s1.marks;
    s1.display();




}