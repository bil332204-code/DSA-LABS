
#include <iostream>
using namespace std;

int main() {
    int numbers[5];
    int total = 0;

    cout << "Enter 5 integers: ";
    for (int i = 0; i < 5; i++) {
        cin >> numbers[i];
    }

    
    for (int i = 0; i < 5; i++) {
        total = total + numbers[i];
    }

    cout << "Total = " << total << endl;

    return 0;
}

/*
Test table 

Test input          Expected total    Actual total
1 2 3 4 5            15                15
0 0 0 0 0             0                 0
-2 4 -1 0 3           4                 4

Trace for the first test case (1 2 3 4 5):
i=0   numbers[0]=1   total=1
i=1  numbers[1]=2   total=3
i=2  numbers[2]=3    total=6
i=3    numbers[3]=4  total=10
i=4  numbers[4]=5   total=15
*/