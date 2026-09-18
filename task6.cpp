
#include <iostream>
using namespace std;

int main() {
    int arr[10];

    cout << "Enter 10 integers: ";
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    int count = 0; 

    for (int i = 0; i < 10; i++) {
        bool alreadyThere = false;
        for (int j = 0; j < count; j++) {
            if (arr[j] == arr[i]) {
                alreadyThere = true;
                break;
            }
        }

        if (!alreadyThere) {
            int temp = arr[count];
            arr[count] = arr[i];
            arr[i] = temp;
            count++;
        }
    }

    cout << "Unique values (in original order): ";
    for (int i = 0; i < count; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Count = " << count << endl;


    return 0;
}