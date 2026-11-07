#ifndef QUEUE_H
#define QUEUE_H 
#include "double linked list.h"
class myQueue
{
private:

    DoublelinkedList<int>  buffer{} ;

public:
    myQueue();
    ~myQueue();
    // User Interface
    bool dequeue(int &data);
    bool enqueue(int data);
    bool isEmpty();

};

#endif