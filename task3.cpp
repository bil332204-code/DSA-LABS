
#include <iostream>
using namespace std;

class Student {
public:
    int rollNumber;
    int marks;

    void display() {
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main() {
    Student s1, s2;

    s1.rollNumber = 1;
    s1.marks = 75;

    s2.rollNumber = 2;
    s2.marks = 90;

    //Expected output:
    //Roll Number:1
    //Marks:75
    //Roll Number:2
    //Marks:90
    cout << "Before change:" << endl;
    s1.display();
    s2.display();

    
    s1.marks = 80;

    cout << "\nAfter changing s1.marks to 80:" << endl;
    s1.display();
    s2.display();

    /*
    Prediction: s2.marks does NOT change, it stays 90.
    Reason: s1 and s2 are two separate objects, each with its own copy
    of the data members (rollNumber, marks). Changing s1.marks only
    touches the memory belonging to s1 - it has nothing to do with s2's
    memory. That's basically the whole point of objects having their
    own data.
    */

    return 0;
}