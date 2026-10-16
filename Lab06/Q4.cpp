// Name: Bilal Ahmed
// Registration No: 573512
// Section: D
// DSA Lab 06 Task 4
// Code prepared with ChatGPT assistance

#include<iostream>
using namespace std;

int items[5];
int front=-1,rear=-1;

void enqueue(int value){
 if(rear==4){
    cout<<"Queue full, cant insert "<<value<<endl;
    return;
 }
 if(front==-1){
   front=0;
 }
 rear++;
 items[rear]=value;
 cout<<value<<" inserted"<<endl;
}

void display(){
 if(front==-1){
  cout<<"Queue empty"<<endl;
  return;
 }
 cout<<"Queue: ";
 for(int i=front;i<=rear;i++){
    cout<<items[i]<<" ";
 }
 cout<<endl;
}

int main(){
 display();
 enqueue(10);
 enqueue(20);
 enqueue(30);
 display();
 enqueue(40);
 enqueue(50);
 display();
 enqueue(60); // not possible
 return 0;
}
