//name: Bilal Ahmed
//registration no: 573512
//section: D

#include<iostream>
using namespace std;

int items[5];
int top=-1;

void push(int val){
if(top==4){
cout<<"Stack full"<<endl;
return;
}
top++;
items[top]=val;
cout<<val<<" pushed"<<endl;
}

void pop(){
if(top==-1){
cout<<"Stack empty, cannot pop"<<endl;
}
else{
cout<<items[top]<<" popped"<<endl;
top--;
}
}

void peek(){
if(top==-1)
cout<<"Stack empty"<<endl;
else
cout<<"Top is "<<items[top]<<endl;
}

void display(){
if(top==-1){
cout<<"Nothing in stack"<<endl;
return;
}
cout<<"Stack: ";
for(int i=top;i>=0;i--){
cout<<items[i]<<" ";
}
cout<<endl;
}

int main(){
push(10);
push(20);
push(30);
display();
pop();
peek();
push(40);
push(50);
push(60);
display();
push(70);
pop();
pop();
pop();
pop();
pop();
pop();
peek();
return 0;
}
