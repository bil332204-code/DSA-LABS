#include<iostream>
using namespace std;

int main(){
    int n;

    cout << "Enter number of students (1-10) : ";
    cin >> n;

    if(n < 1 || n > 10){
        cout << "n must be between 1 and 10.";
        return 1;
    }

    int* marks = new int[n];

    cout << "Enter " << n << " marks : ";
    for(int i = 0; i < n; i++){
        cin >> *(marks + i);
    }

    int* newBlock = new int[n + 1];

    for(int i = 0; i < n; i++){
        *(newBlock + i) = *(marks + i);
    }

    cout << "Enter new student's mark : ";
    cin >> *(newBlock + n);

   
    delete[] marks;

    marks = newBlock;
    n = n + 1;

    cout << "\nUpdated marks : ";
    for(int i = 0; i < n; i++){
        cout << *(marks + i) << " ";
    }
    cout << endl;

    delete[] marks;
    marks = nullptr;

    return 0;
}