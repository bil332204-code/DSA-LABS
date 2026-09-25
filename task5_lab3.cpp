#include<iostream>
#include <string>
using namespace std;

struct Student{

    string name;
    int roll_no;
    float marks;
};

void displayIfExists(const Student* p){
    if(p){//alternative way than p!=nullptr
        cout<<"The Student name is : "<<p->name<<" with roll no : "<<p->roll_no<<" having marks "<<p->marks<<endl;
    }else{
        cout<<"No Record Available"<<endl;
    }
} 

int main(){

    Student* p=nullptr;
    displayIfExists(p);

    p= new Student{};
    p->name="Bilal Ahmed";
    p->roll_no=573512;
    p->marks=98.5;
    displayIfExists(p);  
    
    delete p;
    p=nullptr;
    displayIfExists(p);

    return 0;
}