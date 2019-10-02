#include <iostream>
#include "QueueLL.hpp"

using namespace std;

QueueLL::QueueLL()
{
    queueFront = nullptr;
    queueEnd = nullptr;
}

QueueLL::~QueueLL()
{
    while( !isEmpty() )
        dequeue();
}

bool QueueLL::isEmpty()
{
    /*if(queueFront == nullptr || queueEnd == nullptr)
        return true;
    return false;*/
    return (!queueFront || !queueEnd);
}

// TODO
void QueueLL::enqueue(int key)
{
    if(isEmpty()){
        Node *nn = new Node;
        nn->key = key;
        nn->next = nullptr;
        queueFront = nn;
        queueEnd = nn;
    }
    else{
        Node *nn = new Node;
        nn->key = key;
        queueEnd->next = nn;
        queueEnd = nn;
    }
}

//TODO
void QueueLL::dequeue()
{
    if(!isEmpty())
    {
        if (queueEnd != queueFront){
            Node *nn = new Node;
            nn = queueFront;
            queueFront = queueFront->next;
            delete nn;
        }
        else{
            Node *nn = new Node;
            nn = queueFront;
            delete nn;
            queueFront = nullptr;
            queueEnd = nullptr;
        }
    }
    else{
        cout<<"queue is empty. can not deque"<<endl;
    }
}

int QueueLL::peek()
{
    if( !isEmpty() )
        return queueFront->key;
    else
    {
        cout<< " queue is empty. can not peek"<<endl;
        return -1;
    }
    //return 0;
}
