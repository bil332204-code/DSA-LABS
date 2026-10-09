// Name: Bilal Ahmed
// Registration No: 573512
// Section: D
// Lab 05 - Task 5
// AI assistance was used to check the program.

#include<iostream>
using namespace std;

class ArrayStack{
private:
  int items[5];
  int top;

public:
 ArrayStack(){
   top=-1;
 }

 bool IsEmpty(){
   return top==-1;
 }

 bool IsFull(){
   return top==4;
 }

 void Push(int value){
   if(IsFull()){
     cout<<"Stack overflow. Cannot push "<<value<<endl;
   }
   else{
     top++;
     items[top]=value;
     cout<<"Pushed: "<<value<<endl;
   }
 }

 void Pop(){
    if(IsEmpty()){
      cout<<"Stack underflow. Nothing to pop"<<endl;
    }
    else{
      cout<<"Popped: "<<items[top]<<endl;
      top--;
    }
 }

 void Peek(){
    if(IsEmpty()){
      cout<<"Stack underflow. Stack is empty"<<endl;
    }
    else{
      cout<<"Top: "<<items[top]<<endl;
    }
 }

 void Display(){
   if(IsEmpty()){
      cout<<"Stack is empty"<<endl;
      return;
   }
   cout<<"Top to bottom: ";
   for(int i=top;i>=0;i--){
     cout<<items[i]<<" ";
   }
   cout<<endl;
 }
};

int main(){
 ArrayStack s;
 s.Push(10);
 s.Push(20);
 s.Push(30);
 s.Push(40);
 s.Push(50);
 s.Display();
 s.Push(60);
 s.Pop();
 s.Peek();
 s.Display();
 s.Pop();
 s.Pop();
 s.Pop();
 s.Pop();
 s.Display();
 s.Pop();
 s.Peek();
 return 0;
}
