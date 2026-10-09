// Name: Bilal Ahmed
// Registration No: 573512
// Section: D
// Lab 05 - Task 1
// AI assistance was used to check the program.

#include<iostream>
using namespace std;

class DoublyList{
 private:
 struct node{
   int data;
   node* next;
   node* prev;
 };
 node* head;
 node* tail;

 public:
 DoublyList(){
    head=nullptr;
    tail=nullptr;
 }

 void AddNode(int value){
    node* temp=new node;
    temp->data=value;
    temp->next=nullptr;
    temp->prev=tail;

    if(head==nullptr){
       head=temp;
       tail=temp;
    }
    else{
       tail->next=temp;
       tail=temp;
    }
 }

 void PrintForward(){
   if(head==nullptr){
      cout<<"List is empty"<<endl;
      return;
   }
   node* temp=head;
   cout<<"Forward: ";
   while(temp!=nullptr){
      cout<<temp->data<<" ";
      temp=temp->next;
   }
   cout<<endl;
 }

 void PrintReverse(){
    if(tail==nullptr){
      cout<<"List is empty"<<endl;
      return;
    }
    node* temp=tail;
    cout<<"Reverse: ";
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
    cout<<endl;
 }

 void ClearList(){
    node* temp=head;
    while(temp!=nullptr){
      node* nextNode=temp->next;
      delete temp;
      temp=nextNode;
    }
    head=nullptr;
    tail=nullptr;
 }
};

int main(){
 DoublyList list;
 int n,value;
 cout<<"How many nodes? ";
 cin>>n;
 if(n<0){
   cout<<"Count cannot be negative"<<endl;
   return 0;
 }
 for(int i=0;i<n;i++){
    cout<<"Enter value "<<i+1<<": ";
    cin>>value;
    list.AddNode(value);
 }
 list.PrintForward();
 list.PrintReverse();
 list.ClearList();
 return 0;
}
