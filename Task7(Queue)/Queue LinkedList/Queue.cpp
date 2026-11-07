#include "Queue.h"

myQueue::myQueue() 
{
}
myQueue::~myQueue()
{
}
bool myQueue::isEmpty()
{
    return buffer.empty();
}

bool myQueue::dequeue(int &data)
{
    bool res = false;
    if (isEmpty())
    {
        res = false;
    }
    else
    {
        data=buffer.getFront();
        buffer.deleteFront();
        res=true;
    }
    return res;
}
bool myQueue::enqueue(int data)
{
    bool res = false;
    buffer.insertBack(data);
    res =true;
    return res;
}