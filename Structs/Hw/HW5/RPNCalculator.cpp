#include <cstddef>
#include <iostream>
#include "RPNCalculator.hpp"

using namespace std;

RPNCalculator::RPNCalculator(){
    stackHead = NULL;
}

RPNCalculator::~RPNCalculator(){
    while(!isEmpty())
        pop();
    stackHead = NULL;
}

bool RPNCalculator::isEmpty(){
    return (stackHead == NULL);
}

void RPNCalculator::push(float num){
    Operand* nn = new Operand;
    nn->number = num;
    nn->next = NULL;
    nn->next = stackHead;
    stackHead = nn;
}

void RPNCalculator::pop()
{
    if(!isEmpty())
    {
        Operand* temp = stackHead;
        stackHead = stackHead->next;
        delete temp;
    }
    else
    {
        cout<<"Stack empty, cannot pop an item."<<endl;
    }
}

Operand *RPNCalculator::peek()
{
    if(!isEmpty())
        return stackHead;
    else{
        cout<<"Stack empty, cannot peek."<<endl;
        return NULL;
    }
  //return 0;
}

bool RPNCalculator::compute(string sym){
    float op1 = 0, op2 = 0;
    float result = 0;
    if ((sym == "+")||(sym=="*")){
        if (!isEmpty()){
            op1 = peek()->number;
            pop();
        }
        else{
            cout << "err: not enough operands" << endl;
            return false;
        }
        if (!isEmpty()){
            op2 = peek()->number;
            pop();
        }
        else{
            cout << "err: not enough operands" << endl;
            push(op1);
            return false;
        }
        if (sym == "+"){
            result = op1 + op2;
            push(result);
        }
        else{
            result = op1 * op2;
            push(result);
        }
        return true;
    }
    else{
        cout << "err: invalid operation" << endl;
        return false;
    }
}