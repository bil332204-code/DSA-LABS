// Name: Bilal Ahmed
// Registration No: 573512
// Section: D
// Lab 05 - Task 3
// AI assistance was used to check the program.

#include<iostream>
using namespace std;

class CircularList{
private:
 struct node{
   int data;
   node* next;
 };
 node* head;
 node* tail;

public:
 CircularList(){
   head=nullptr;
   tail=nullptr;
 }

 void AddNode(int value){
    node* temp=new node;
    temp->data=value;
    if(head==nullptr){
       head=temp;
       tail=temp;
       temp->next=head;
    }
    else{
       temp->next=head;
       tail->next=temp;
       tail=temp;
    }
 }

 void PrintList(){
   if(head==nullptr){
      cout<<"List is empty"<<endl;
      return;
   }
   node* temp=head;
   cout<<"List: ";
   do{
     cout<<temp->data<<" ";
     temp=temp->next;
   }while(temp!=head);
   cout<<endl;
 }

 int CountNodes(){
    if(head==nullptr)
      return 0;
    int count=0;
    node* temp=head;
    do{
      count++;
      temp=temp->next;
    }while(temp!=head);
    return count;
 }

 void ClearList(){
    if(head==nullptr) return;
    tail->next=nullptr;
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
 CircularList list;
 int n,value;
 cout<<"How many nodes? ";
 cin>>n;
 if(n<0){
     cout<<"Invalid count"<<endl;
     return 0;
 }
 for(int i=0;i<n;i++){
    cout<<"Enter value "<<i+1<<": ";
    cin>>value;
    list.AddNode(value);
 }
 list.PrintList();
 cout<<"Total nodes: "<<list.CountNodes()<<endl;
 // We stop when we reach head again, not nullptr.
 list.ClearList();
 return 0;
}
