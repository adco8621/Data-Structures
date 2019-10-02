#include <iostream>
#include "StackARR.hpp"
using namespace std;

Stack_Arr::Stack_Arr(){
  arr = NULL;
  top = -1;
}

/*Stack_Arr::Stack_Arr(int cap){
  arr = new int[cap];
  top = -1;
  capacity = cap;
}*/

void Stack_Arr::initialise(int cap){
  arr = new int[cap];
  top = -1;
  capacity = cap;
}

bool Stack_Arr::isEmpty()
{
  return top==-1;
}
bool Stack_Arr::isFull()
{
  return top==capacity-1;
}

void Stack_Arr::push(int num)
{
    if(isFull())
    {
        cout<< "stack is full. Can not push"<<endl;

    }
    else{
      top++;
      arr[top] = num;
    }
}

void Stack_Arr::pop()
{
  if(isEmpty())
  {
    cout<<" stack is empty"<<endl;
  }
  else{
    arr[top] = -999;
    top--;
  }
}

int Stack_Arr::peek(){
  if(isEmpty())
  {
    cout<<" stack is empty"<<endl;
    return -999;
  }
  else{
    return arr[top];
  }
}

void Stack_Arr::printStack()
{
    cout<< "printing the stack from top to bottom"<<endl;
    for(int i=top; i>=0;i--)
    {
        cout<< arr[i];
        if(i>0)
          cout<< " ,";
    }
    cout<<endl;
}
