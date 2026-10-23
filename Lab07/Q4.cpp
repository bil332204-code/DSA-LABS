//name: Bilal Ahmed
//registration no: 573512
//section: D
#include<iostream>
using namespace std;
class CircularQueue{
private:
int items[5];
int front,rear;
public:
CircularQueue(){front=-1;rear=-1;}
bool IsEmpty(){return front==-1;}
bool IsFull(){return !IsEmpty() && (rear+1)%5==front;}
void Enqueue(int x){
if(IsFull()){cout<<"queue full"<<endl;return;}
if(IsEmpty()){front=0;rear=0;}
else rear=(rear+1)%5;
items[rear]=x;
}
int Dequeue(){
if(IsEmpty()){cout<<"queue empty"<<endl;return -1;}
int x=items[front];
if(front==rear){front=-1;rear=-1;}
else front=(front+1)%5;
return x;
}
void Display(){
if(IsEmpty()){cout<<"queue empty"<<endl;return;}
cout<<"students: ";
int i=front;
while(true){
cout<<items[i]<<" ";
if(i==rear) break;
i=(i+1)%5;
}
cout<<endl;
}
void RotateTurn(){
if(IsEmpty()){cout<<"no students"<<endl;return;}
int x=Dequeue();
cout<<"served student "<<x<<endl;
Enqueue(x);
Display();
}
};
int main(){
CircularQueue q;
q.RotateTurn();
q.Enqueue(101);q.Enqueue(102);q.Enqueue(103);
q.Display();
for(int i=0;i<5;i++) q.RotateTurn();
CircularQueue q2;
q2.Enqueue(105);
q2.RotateTurn();
return 0;
}
