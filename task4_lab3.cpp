#include<iostream>
#include <string>
using namespace std;

struct Student{

    string name;
    int roll_no;
    float marks;
};

void displayStudent(const Student* p){
    cout<<"\nThe Student name is : "<<p->name<<" with roll no : "<<p->roll_no<<" having marks "<<p->marks<<endl;
}
void updateMarks(Student* p,float newMarks){
     
    p->marks=newMarks;
    cout<<"\nUpdating .......................\ndonee......\n";
}
int main(){

    Student* p=new Student{};

    p->name="Bilal Ahmed";
    p->roll_no=573512;
    p->marks=98.5;
    
    displayStudent(p);
    updateMarks(p,101.5);
    displayStudent(p);
    delete p;
    p=nullptr;


    return 0;
}