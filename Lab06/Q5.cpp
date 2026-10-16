//name: Bilal Ahmed
//registration no: 573512
//section: D

#include<iostream>
using namespace std;

int items[5];
int front=-1,rear=-1;

void enqueue(int value){
if(rear==4){
cout<<"Queue full"<<endl;
return;
}
if(front==-1){
front=0;
}
rear++;
items[rear]=value;
cout<<value<<" inserted"<<endl;
}

void dequeue(){
if(front==-1){
cout<<"Queue empty, cannot remove"<<endl;
return;
}
cout<<items[front]<<" removed"<<endl;
if(front==rear){
front=-1;
rear=-1;
}
else{
front++;
}
}

void peekFront(){
if(front==-1)
cout<<"Queue empty"<<endl;
else
cout<<"Front is "<<items[front]<<endl;
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
enqueue(10);
enqueue(20);
enqueue(30);
display();
dequeue();
peekFront();
display();
dequeue();
dequeue();
dequeue();
peekFront();
enqueue(40);
display();
return 0;
}
