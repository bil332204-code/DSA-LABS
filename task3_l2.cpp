#include<iostream>
using namespace std;

int main(){
    int sales[2][3];
    int (*rowPtr)[3] = sales;

    int branchTotal[2] = {0, 0};
    int dayTotal[3] = {0, 0, 0};
    
    for(int r = 0; r < 2; r++){
        cout << "Enter sales for Branch " << (r+1) << " (3 values): ";
        for(int c = 0; c < 3; c++){
            cin >> *(*(rowPtr + r) + c);
            branchTotal[r] += *(*(rowPtr + r) + c);
            dayTotal[c]    += *(*(rowPtr + r) + c);
        }
    }

    cout << "\nSales Table:\n";
    for(int r = 0; r < 2; r++){
        for(int c = 0; c < 3; c++){
            cout << *(*(rowPtr + r) + c) << " ";
        }
        cout << endl;
    }

    cout << "\nBranch totals: " << branchTotal[0] << " and " << branchTotal[1] << endl;
    cout << "Day totals: " << dayTotal[0] << ", " << dayTotal[1] << " and " << dayTotal[2] << endl;

    return 0;
}