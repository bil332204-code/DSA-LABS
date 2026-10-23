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
void Enqueue(int value){
if(IsFull()){cout<<"queue full"<<endl;return;}
if(IsEmpty()){front=0;rear=0;}
else rear=(rear+1)%5;
items[rear]=value;
cout<<value<<" added"<<endl;
}
void Dequeue(){
if(IsEmpty()){cout<<"queue empty"<<endl;return;}
cout<<items[front]<<" removed"<<endl;
if(front==rear){front=-1;rear=-1;}
else front=(front+1)%5;
}
void Peek(){
if(IsEmpty()) cout<<"queue empty"<<endl;
else cout<<"front is "<<items[front]<<endl;
}
void Display(){
if(IsEmpty()){cout<<"queue empty"<<endl;return;}
int i=front;
cout<<"queue: ";
while(true){
cout<<items[i]<<" ";
if(i==rear) break;
i=(i+1)%5;
}
cout<<endl;
cout<<"front="<<front<<" rear="<<rear<<endl;
}
};
int main(){
CircularQueue q;
q.Enqueue(10);q.Enqueue(20);q.Enqueue(30);q.Enqueue(40);q.Enqueue(50);
q.Dequeue();q.Dequeue();
q.Enqueue(60);q.Enqueue(70);
q.Display();q.Peek();q.Enqueue(80);
q.Dequeue();q.Dequeue();q.Dequeue();q.Dequeue();q.Dequeue();
q.Dequeue();q.Enqueue(90);q.Display();
return 0;
}
