//name: Bilal Ahmed
//registration no: 573512
//section: D
#include<iostream>
using namespace std;
class LinkedQueue{
private:
struct node{int data;node* next;};
node* front;
node* rear;
public:
LinkedQueue(){front=nullptr;rear=nullptr;}
bool IsEmpty(){return front==nullptr;}
void Enqueue(int value){
node* p=new node;
p->data=value;
p->next=nullptr;
if(IsEmpty()){front=p;rear=p;}
else{rear->next=p;rear=p;}
cout<<value<<" added"<<endl;
}
void Dequeue(){
if(IsEmpty()){cout<<"queue empty"<<endl;return;}
node* p=front;
cout<<p->data<<" removed"<<endl;
front=front->next;
if(front==nullptr) rear=nullptr;
delete p;
}
void Peek(){
if(IsEmpty()) cout<<"queue empty"<<endl;
else cout<<"front is "<<front->data<<endl;
}
void Display(){
if(IsEmpty()){cout<<"queue empty"<<endl;return;}
node* p=front;
cout<<"queue: ";
while(p!=nullptr){cout<<p->data<<" ";p=p->next;}
cout<<endl;
}
void ClearQueue(){
while(front!=nullptr){
node* p=front;
front=front->next;
delete p;
}
rear=nullptr;
}
~LinkedQueue(){ClearQueue();}
};
int main(){
LinkedQueue q;
q.Dequeue();
q.Enqueue(10);q.Enqueue(20);q.Enqueue(30);
q.Dequeue();q.Display();q.Peek();
q.Dequeue();q.Dequeue();q.Dequeue();
q.Enqueue(40);q.Display();q.Dequeue();
q.Enqueue(50);q.Enqueue(60);
q.ClearQueue();
return 0;
}
