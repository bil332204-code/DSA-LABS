// Name: Bilal Ahmed
// Registration No: 573512
// Section: D
// DSA Lab 06 Task 2

#include<iostream>
using namespace std;

struct Node{
 int data;
 Node* next;
};
Node* top=nullptr;

void push(int x){
 Node* n=new Node;
 n->data=x;
 n->next=top;
 top=n;
 cout<<x<<" pushed"<<endl;
}

void pop(){
 if(top==nullptr){
   cout<<"Stack empty, cannot pop"<<endl;
   return;
 }
 Node* temp=top;
 cout<<top->data<<" popped"<<endl;
 top=top->next;
 delete temp;
}

void peek(){
 if(top==nullptr){
   cout<<"Stack empty"<<endl;
 }
 else cout<<"Top is "<<top->data<<endl;
}

void display(){
 if(top==nullptr){
    cout<<"Stack empty"<<endl;
    return;
 }
 Node* p=top;
 cout<<"Stack: ";
 while(p!=nullptr){
  cout<<p->data<<" ";
  p=p->next;
 }
 cout<<endl;
}

void clearStack(){
 while(top!=nullptr){
   Node* p=top;
   top=top->next;
   delete p;
 }
}

int main(){
 push(5);
 push(15);
 push(25);
 display();
 pop();
 peek();
 pop();
 pop();
 pop(); // empty pop test
 push(35);
 push(45);
 display();
 clearStack();
 return 0;
}
