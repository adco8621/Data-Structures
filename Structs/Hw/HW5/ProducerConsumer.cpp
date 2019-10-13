#include <cstddef>
#include <iostream>
#include "ProducerConsumer.hpp"

using namespace std;

ProducerConsumer::ProducerConsumer(){
    queueFront = 0;
    queueEnd = 0;
}

bool ProducerConsumer::isEmpty(){
    return ((queueEnd == queueFront) &&(queue[queueFront] == ""));
}

bool ProducerConsumer::isFull(){
    return ((queueEnd == queueFront) && (queue[queueFront] != ""));
}

void ProducerConsumer::enqueue(string in){
    if (!isFull()){
        queue[queueEnd] = in;

        if (queueEnd != 19){
            queueEnd++;
        }
        else{
            queueEnd = 0;
        }
    }
    else{
        cout << "Queue full, cannot add new item" << endl;
    }
}

void ProducerConsumer::dequeue(){
    if (!isEmpty()){
        queue[queueFront] = "";
        if (queueFront != 19){
            queueFront++;
        }
        else{
            queueFront = 0;
        }
    }
    else{
        cout << "Queue empty, cannot dequeue an item" << endl;
    }
}

string ProducerConsumer::peek(){
    if (!isEmpty()){
        return queue[queueFront];
    }
    else{
        cout << "Queue empty, cannot peek" << endl;
        return "";
    }
}

int ProducerConsumer::queueSize(){
    if (isFull()){
        return SIZE;
    }
    else if (isEmpty()){
        return 0;
    }
    else{
        if (queueFront < queueEnd){
            return (queueEnd - queueFront);
        }
        else{
            return (SIZE - (queueFront - queueEnd));
        }
    }
}