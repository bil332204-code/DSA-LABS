//name: Bilal Ahmed
//registration no: 573512
//section: D
#include<iostream>
using namespace std;
class ArrayQueue{
private:
int items[5];
int front,rear;
public:
ArrayQueue(){front=-1;rear=-1;}
bool IsEmpty(){return front==-1;}
bool IsFull(){return rear==4;}
void Enqueue(int value){
if(IsFull()){cout<<"queue full"<<endl;return;}
if(IsEmpty()) front=0;
rear++;
items[rear]=value;
cout<<value<<" added"<<endl;
}
void Dequeue(){
if(IsEmpty()){cout<<"queue empty"<<endl;return;}
cout<<items[front]<<" removed"<<endl;
if(front==rear){front=-1;rear=-1;}
else front++;
}
void Peek(){
if(IsEmpty()) cout<<"queue empty"<<endl;
else cout<<"front is "<<items[front]<<endl;
}
void Display(){
if(IsEmpty()){cout<<"queue empty"<<endl;return;}
cout<<"queue: ";
for(int i=front;i<=rear;i++) cout<<items[i]<<" ";
cout<<endl;
}
};
int main(){
ArrayQueue q;
q.Enqueue(10);q.Enqueue(20);q.Enqueue(30);q.Enqueue(40);q.Enqueue(50);
q.Dequeue();q.Dequeue();
q.Enqueue(60);
q.Display();q.Peek();
q.Dequeue();q.Dequeue();q.Dequeue();
q.Dequeue();
q.Enqueue(70);q.Display();
return 0;
}
