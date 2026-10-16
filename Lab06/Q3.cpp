// Name: Bilal Ahmed
// Registration No: 573512
// Section: D
// DSA Lab 06 Task 3

#include<iostream>
#include<string>
using namespace std;

char arr[20];
int top=-1;

void push(char c){
 if(top==19){
   cout<<"Stack full"<<endl;
   return;
 }
 top++;
 arr[top]=c;
}

char pop(){
 if(top==-1){
    return '\0';
 }
 char c=arr[top];
 top--;
 return c;
}

int main(){
 string word;
 cout<<"Enter a word (max 20 letters): ";
 cin>>word;
 if(word.length()>20){
   cout<<"Word is too long"<<endl;
   return 0;
 }
 for(int i=0;i<(int)word.length();i++){
   push(word[i]);
 }
 cout<<"Reverse: ";
 while(top!=-1){
    cout<<pop();
 }
 cout<<endl;
 return 0;
}
