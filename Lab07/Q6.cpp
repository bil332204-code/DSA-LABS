//name: Bilal Ahmed
//registration no: 573512
//section: D
#include<iostream>
using namespace std;
class LinkedDeque{
private:
struct node{int data;node* next;node* prev;};
node* front;
node* rear;
public:
LinkedDeque(){front=nullptr;rear=nullptr;}
void InsertFront(int x){
node* p=new node;
p->data=x;p->prev=nullptr;p->next=front;
if(front==nullptr){front=p;rear=p;}
else{front->prev=p;front=p;}
}
void InsertRear(int x){
node* p=new node;
p->data=x;p->next=nullptr;p->prev=rear;
if(rear==nullptr){front=p;rear=p;}
else{rear->next=p;rear=p;}
}
void DeleteFront(){
if(front==nullptr){cout<<"deque empty"<<endl;return;}
node* p=front;
cout<<p->data<<" deleted"<<endl;
front=front->next;
if(front==nullptr) rear=nullptr;
else front->prev=nullptr;
delete p;
}
void DeleteRear(){
if(rear==nullptr){cout<<"deque empty"<<endl;return;}
node* p=rear;
cout<<p->data<<" deleted"<<endl;
rear=rear->prev;
if(rear==nullptr) front=nullptr;
else rear->next=nullptr;
delete p;
}
void Display(){
if(front==nullptr){cout<<"deque empty"<<endl;return;}
cout<<"deque: ";
node* p=front;
while(p!=nullptr){cout<<p->data<<" ";p=p->next;}
cout<<endl;
}
void ClearDeque(){
while(front!=nullptr){
node* p=front;
front=front->next;
delete p;
}
rear=nullptr;
}
~LinkedDeque(){ClearDeque();}
};
int main(){
LinkedDeque d;
int c=0,x;
while(c!=6){
cout<<"\n1 insert front\n2 insert rear\n3 delete front\n4 delete rear\n5 display\n6 exit\nchoice: ";
cin>>c;
if(c==1){cout<<"number: ";cin>>x;d.InsertFront(x);}
else if(c==2){cout<<"number: ";cin>>x;d.InsertRear(x);}
else if(c==3) d.DeleteFront();
else if(c==4) d.DeleteRear();
else if(c==5) d.Display();
else if(c==6) cout<<"bye"<<endl;
else cout<<"wrong choice"<<endl;
}
d.ClearDeque();
return 0;
}
