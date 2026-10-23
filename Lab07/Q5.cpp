//name: Bilal Ahmed
//registration no: 573512
//section: D
#include<iostream>
using namespace std;
class ArrayDeque{
private:
int items[5];
int front,rear;
public:
ArrayDeque(){front=-1;rear=-1;}
bool IsEmpty(){return front==-1;}
bool IsFull(){return !IsEmpty() && (rear+1)%5==front;}
void InsertFront(int x){
if(IsFull()){cout<<"deque full"<<endl;return;}
if(IsEmpty()){front=0;rear=0;}
else front=(front+4)%5;
items[front]=x;
}
void InsertRear(int x){
if(IsFull()){cout<<"deque full"<<endl;return;}
if(IsEmpty()){front=0;rear=0;}
else rear=(rear+1)%5;
items[rear]=x;
}
void DeleteFront(){
if(IsEmpty()){cout<<"deque empty"<<endl;return;}
cout<<items[front]<<" removed front"<<endl;
if(front==rear){front=-1;rear=-1;}
else front=(front+1)%5;
}
void DeleteRear(){
if(IsEmpty()){cout<<"deque empty"<<endl;return;}
cout<<items[rear]<<" removed rear"<<endl;
if(front==rear){front=-1;rear=-1;}
else rear=(rear+4)%5;
}
void Display(){
if(IsEmpty()){cout<<"deque empty"<<endl;return;}
cout<<"deque: ";
int i=front;
while(true){
cout<<items[i]<<" ";
if(i==rear) break;
i=(i+1)%5;
}
cout<<endl;
}
};
int main(){
ArrayDeque d;
d.InsertRear(20);d.InsertFront(10);d.InsertRear(30);d.Display();
d.DeleteRear();d.DeleteFront();d.Display();
d.InsertFront(5);d.InsertRear(30);d.InsertRear(40);d.InsertFront(1);
d.Display();
d.InsertFront(0);d.InsertRear(50);
d.DeleteFront();d.DeleteRear();d.DeleteFront();d.DeleteRear();d.DeleteFront();
d.DeleteFront();
d.InsertFront(8);d.DeleteRear();d.DeleteFront();
d.InsertRear(9);d.DeleteFront();d.DeleteRear();
return 0;
}
