#include<iostream>
#include <string>
using namespace std;

struct Student{

    string name;
    int roll_no;
    float marks;
};

void create(Student*& p){
    if(p==nullptr){
        p=new Student{};
        cout<<"Enter Student Name : ";
        getline(cin, p->name);
        cout<<"\nEnter Student roll no : ";
        cin>>p->roll_no;
        cout<<"\nEnter Student marks : ";
        cin>>p->marks;
    }else{
        cout<<"Already a record exists.Delete before creating a new record."<<endl;
    }
}

void updateMarks(Student* p){
    if(p){     
        cout<<"Enter marks you want to update : "<<endl;
        cin>>p->marks;
        cout<<"\nUpdating .......................\ndonee......"<<endl;
    }else{
        cout<<"No Record Exists."<<endl;
    }

    }

void deleteStudent(Student*& p){
    if(p){
        delete p;
        p=nullptr;
    }else{
        cout<<"No Record Exists."<<endl;
    }
}

void displayIfExists(const Student* p){
    if(p){//alternative way than p!=nullptr
        cout<<"The Student name is : "<<p->name<<" with roll no : "<<p->roll_no<<" having marks "<<p->marks<<endl;
    }else{
        cout<<"No Record Available"<<endl;
    }
} 

void Exit(Student*& p) {
    if (p) {
        delete p;
        p = nullptr;
    }
}

int main() {

    Student* p = nullptr;
    int n;

    while (true) {

        cout << "\n======== Menu ========\n";
        cout << "1. Create\n";
        cout << "2. Display\n";
        cout << "3. Update Marks\n";
        cout << "4. Delete\n";
        cout << "5. Exit\n";
        cout << "======================\n";

        cout << "Enter your choice (1-5): ";
        cin >> n;

        if (n < 1 || n > 5) {
            cout << "Invalid choice! Please enter a number between 1 and 5.\n";
            continue;
        }

        switch (n) {

            case 1:
                create(p);
                break;

            case 2:
                displayIfExists(p);
                break;

            case 3:
                updateMarks(p);
                break;

            case 4:
                deleteStudent(p);
                break;

            case 5:
                Exit(p);
                cout << "Program exited successfully.\n";
                return 0;
        }
    }
}