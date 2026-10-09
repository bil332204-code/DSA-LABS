// Name: Bilal Ahmed
// Registration No: 573512
// Section: D
// Lab 05 - Task 4
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

 void DeleteNode(int value){
    if(head==nullptr){
      cout<<"List is empty"<<endl;
      return;
    }
    node* current=head;
    node* previous=tail;
    do{
      if(current->data==value)
         break;
      previous=current;
      current=current->next;
    }while(current!=head);

    if(current->data!=value){
       cout<<"Value not found"<<endl;
       return;
    }
    if(head==tail){
       delete current;
       head=nullptr;
       tail=nullptr;
    }
    else{
       previous->next=current->next;
       if(current==head)
          head=current->next;
       if(current==tail)
          tail=previous;
       tail->next=head;
       delete current;
    }
    cout<<"Deleted: "<<value<<endl;
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
    if(head==nullptr) return 0;
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
 list.PrintList();
 cout<<"Count: "<<list.CountNodes()<<endl;
 list.DeleteNode(10);

 list.AddNode(10);
 list.AddNode(20);
 list.AddNode(30);
 list.PrintList();
 cout<<"Count: "<<list.CountNodes()<<endl;

 list.DeleteNode(10);
 list.PrintList();
 cout<<"Count: "<<list.CountNodes()<<endl;
 list.DeleteNode(30);
 list.PrintList();
 cout<<"Count: "<<list.CountNodes()<<endl;
 list.DeleteNode(20);
 list.PrintList();
 cout<<"Count: "<<list.CountNodes()<<endl;

 cout<<"\nChecking duplicates"<<endl;
 list.AddNode(10);
 list.AddNode(20);
 list.AddNode(20);
 list.AddNode(30);
 list.PrintList();
 list.DeleteNode(20);
 list.PrintList();
 cout<<"Count: "<<list.CountNodes()<<endl;
 list.DeleteNode(99);
 list.PrintList();
 cout<<"Count: "<<list.CountNodes()<<endl;
 list.ClearList();
 return 0;
}
