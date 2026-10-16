// Name: Bilal Ahmed
// Registration No: 573512
// Section: D
// DSA Lab 06 Task 6
// Code prepared with ChatGPT assistance

#include<iostream>
using namespace std;

int customers[5];
int front=-1,rear=-1;

void addCustomer(){
 if(rear==4){
    cout<<"Queue full, wait till its empty"<<endl;
    return;
 }
 int token;
 cout<<"Enter customer token: ";
 cin>>token;
 if(front==-1){
    front=0;
 }
 rear++;
 customers[rear]=token;
 cout<<"Customer added"<<endl;
}

void serveNext(){
 if(front==-1){
    cout<<"No customer to serve"<<endl;
    return;
 }
 cout<<"Serving token "<<customers[front]<<endl;
 if(front==rear){
   front=-1;
   rear=-1;
 }
 else front++;
}

void viewNext(){
 if(front==-1){
    cout<<"No customer waiting"<<endl;
 }
 else
    cout<<"Next token: "<<customers[front]<<endl;
}

void display(){
 if(front==-1){
    cout<<"Queue is empty"<<endl;
    return;
 }
 cout<<"Waiting tokens: ";
 for(int i=front;i<=rear;i++){
   cout<<customers[i]<<" ";
 }
 cout<<endl;
}

int main(){
 int choice=0;
 while(choice!=5){
    cout<<"\n1. Add customer"<<endl;
    cout<<"2. Serve next"<<endl;
    cout<<"3. View next"<<endl;
    cout<<"4. Display queue"<<endl;
    cout<<"5. Exit"<<endl;
    cout<<"Choice: ";
    cin>>choice;

    if(choice==1) addCustomer();
    else if(choice==2) serveNext();
    else if(choice==3) viewNext();
    else if(choice==4) display();
    else if(choice==5) cout<<"Bye"<<endl;
    else cout<<"Wrong choice"<<endl;
 }
 return 0;
}
