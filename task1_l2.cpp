#include<iostream>
using namespace std;
int main(){
    int sales[5];
    
    int* p = sales;
    
    int total =0;
    
    cout<<"Enter five non negative values : "<<endl;
    
    for(int i=0; i<5 ; i++){
        cin>>*(p+i);
        if(*(p+i)<0){
            cout<<"The values must be positive .";
            i--;
            continue;
        }
        total+=(*(p+i));
    
    }
    for (int i=0;i<5;i++){
        cout<<*(p+i)<<" ";
    
    }
    
    cout<<"\nThe total is : "<<total;
    
    *(p+2)+=2;
    
    total+=2;
    
    cout<<"\nThe updated array is : ";
    
    for (int i=0;i<5;i++){
        cout<<*(p+i)<<" ";
    }
    
    cout<<"\nThe updated total is : "<<total;

    return 0;

}