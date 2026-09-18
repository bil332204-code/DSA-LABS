#include<iostream>
using namespace std;

int main(){
    int rows, cols;

    cout << "Enter number of students : ";
    cin >> rows;
    cout << "Enter number of subjects : ";
    cin >> cols;

    if(rows <= 0 || cols <= 0){
        cout << "Rows and columns must be positive.";
        return 1;
    }

    int** marks = new int*[rows];
    for(int r = 0; r < rows; r++){
        marks[r] = new int[cols];
    }

    for(int r = 0; r < rows; r++){
        cout << "Enter " << cols << " marks for student " << (r+1) << " : ";
        for(int c = 0; c < cols; c++){
            cin >> *(*(marks + r) + c);
        }
    }

    cout << "\nMarks Matrix:\n";
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            cout << *(*(marks + r) + c) << " ";
        }
        cout << endl;
    }

    int bestTotal = 0;
    int bestStudent = 1;

    for(int r = 0; r < rows; r++){
        int total = 0;
        for(int c = 0; c < cols; c++){
            total += *(*(marks + r) + c);
        }
        if(r == 0){
            bestTotal = total;
            bestStudent = 1;
        } else if(total > bestTotal){
            bestTotal = total;
            bestStudent = r + 1;
        }
        cout << "Student " << (r+1) << " total = " << total << endl;
    }

    cout << "\nTop student: " << bestStudent << " with total " << bestTotal << endl;

    for(int r = 0; r < rows; r++){
        delete[] marks[r];
    }
    delete[] marks;
    marks = nullptr;

    return 0;
}