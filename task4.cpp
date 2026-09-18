
#include <iostream>
using namespace std;

int main() {
    int arr[8];

    cout << "Enter 8 integers: ";
    for (int i = 0; i < 8; i++) {
        cin >> arr[i];
    }

    int maxVal = arr[0], minVal = arr[0];
    int maxIndex = 0, minIndex = 0;

    for (int i = 1; i < 8; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
            maxIndex = i;
        }
        if (arr[i] < minVal) {
            minVal = arr[i];
            minIndex = i;
        }
    }
//using strict > and < above means equal values later on don't overwrite the first occurrence we already stored
    cout << "Largest value = " << maxVal << " at index " << maxIndex << endl;
    cout << "Smallest value = " << minVal << " at index " << minIndex << endl;

    return 0;
}