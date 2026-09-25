
#include <iostream>
using namespace std;

void reversearr(int num[],int index){
      if (index<0){
        return;
      }
      
        cout <<num[index]<<" ";
        reversearr(num,index-1);

    }

int main() {
    int arr[6];

    cout << "Enter 6 integers: ";
    for (int i = 0; i < 6; i++) {
        cin >> arr[i];
    }
    
    cout<<"\nThe reversed array is : ";
    reversearr(arr,5);
    cout<<endl;
    

    return 0;
}