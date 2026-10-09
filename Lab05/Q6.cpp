// Name: Bilal Ahmed
// Registration No: 573512
// Section: D
// Lab 05 - Task 6
// AI assistance was used to check the program.

#include<iostream>
using namespace std;

class LinkedStack{
private:
 struct node{
    int data;
    node* next;
 };
 node* top;

public:
 LinkedStack(){
    top=nullptr;
 }

 bool IsEmpty(){
    return top==nullptr;
 }

 void Push(int value){
    node* temp=new node;
    temp->data=value;
    temp->next=top;
    top=temp;
    cout<<"Pushed: "<<value<<endl;
 }

 void Pop(){
    if(IsEmpty()){
      cout<<"Stack underflow. Nothing to pop"<<endl;
      return;
    }
    node* temp=top;
    cout<<"Popped: "<<temp->data<<endl;
    top=top->next;
    delete temp;
 }

 void Peek(){
    if(IsEmpty()){
       cout<<"Stack is empty"<<endl;
    }
    else{
       cout<<"Top: "<<top->data<<endl;
    }
 }

 void Display(){
    if(IsEmpty()){
       cout<<"Stack is empty"<<endl;
       return;
    }
    cout<<"Top to bottom: ";
    node* temp=top;
    while(temp!=nullptr){
       cout<<temp->data<<" ";
       temp=temp->next;
    }
    cout<<endl;
 }

 void ClearStack(){
    node* temp=top;
    while(temp!=nullptr){
       node* nextNode=temp->next;
       delete temp;
       temp=nextNode;
    }
    top=nullptr;
 }
};

int main(){
 LinkedStack s;
 int choice,value;
 do{
    cout<<"\n1 Push\n2 Pop\n3 Peek\n4 Display\n5 Exit\n";
    cout<<"Enter choice: ";
    cin>>choice;
    if(choice==1){
      cout<<"Enter value: ";
      cin>>value;
      s.Push(value);
    }
    else if(choice==2){
      s.Pop();
    }
    else if(choice==3){
      s.Peek();
    }
    else if(choice==4){
      s.Display();
    }
    else if(choice==5){
      cout<<"Exiting"<<endl;
    }
    else{
      cout<<"Invalid choice"<<endl;
    }
 }while(choice!=5);
 s.ClearStack();
 return 0;
}
