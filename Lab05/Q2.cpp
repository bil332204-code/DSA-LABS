// Name: Bilal Ahmed
// Registration No: 573512
// Section: D
// Lab 05 - Task 2
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

 void InsertBefore(int position,int value){
    if(position<1 || head==nullptr){
      cout<<"Invalid position"<<endl;
      return;
    }
    node* current=head;
    int count=1;
    while(current!=nullptr && count<position){
      current=current->next;
      count++;
    }
    if(current==nullptr){
      cout<<"Invalid position"<<endl;
      return;
    }
    node* temp=new node;
    temp->data=value;
    temp->next=current;
    temp->prev=current->prev;

    if(current->prev!=nullptr)
       current->prev->next=temp;
    else
       head=temp;
    current->prev=temp;
    cout<<"Value inserted"<<endl;
 }

 void DeleteNode(int value){
    node* current=head;
    while(current!=nullptr && current->data!=value){
      current=current->next;
    }
    if(current==nullptr){
      cout<<"Value not found"<<endl;
      return;
    }
    if(current->prev!=nullptr)
        current->prev->next=current->next;
    else
        head=current->next;

    if(current->next!=nullptr)
        current->next->prev=current->prev;
    else
        tail=current->prev;

    delete current;
    cout<<"Value deleted"<<endl;
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
 list.AddNode(10);
 list.AddNode(20);
 list.AddNode(30);
 cout<<"Starting list"<<endl;
 list.PrintForward();
 list.PrintReverse();

 int choice,position,value;
 do{
   cout<<"\n1 Insert before position\n2 Delete value\n3 Print list\n4 Add at end\n5 Clear list\n0 Exit\n";
   cout<<"Choice: ";
   cin>>choice;
   if(choice==1){
      cout<<"Enter position and value: ";
      cin>>position>>value;
      list.InsertBefore(position,value);
      list.PrintForward();
      list.PrintReverse();
   }
   else if(choice==2){
      cout<<"Enter value to delete: ";
      cin>>value;
      list.DeleteNode(value);
      list.PrintForward();
      list.PrintReverse();
   }
   else if(choice==3){
     list.PrintForward();
     list.PrintReverse();
   }
   else if(choice==4){
      cout<<"Enter value: ";
      cin>>value;
      list.AddNode(value);
      list.PrintForward();
      list.PrintReverse();
   }
   else if(choice==5){
      list.ClearList();
      cout<<"List cleared"<<endl;
      list.PrintForward();
      list.PrintReverse();
   }
   else if(choice!=0){
      cout<<"Wrong choice"<<endl;
   }
 }while(choice!=0);
 list.ClearList();
 return 0;
}
