#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    if(n<=0){
        cout<<"The value must be positive : ";
        return 1;
    }

    int* marks=new int[n];
    int count=0;
    int total=0;
    
    cout<<"Enter "<<n<<" marks : ";
    for(int i =0 ; i<n ; i++){
        cin>>*(marks + i);

        if(*(marks + i)<0 || *(marks + i)>100){
            cout<<"The values must be between 0 and 100.";
            i--;
            continue;
        }
        if(*(marks + i)>50){
            count++;
        }

        total+=*(marks + i);
    }

    double average= (double)total/n;
    cout<<"\nThe marks are : ";
    for (int i=0;i<n;i++){
        cout<<*(marks + i)<<" ";
    }
    cout <<"Total = "<<total<<" ; Average : "<<average<<" ; pass count : "<<count;

    delete[] marks;
    marks=nullptr;

    return 0;
}
