#include "Queue.h"

myQueue::myQueue() : readIndex(0), writeIndex(1), cap(5)
{
    buffer = new int[cap];
}
myQueue::~myQueue()
{
    delete[] buffer;
}
bool myQueue::isEmpty()
{
    return size==0;
}
bool myQueue::isFull()
{
    return size==cap;
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
        // Shift read index
        readIndex++;
        readIndex %= cap;
        // update data with read data from buffer
        data = buffer[readIndex];
        res = true;
        size--;
    }
    return res;
}
bool myQueue::enqueue(int data)
{
    bool res = false;
    if (isFull() )
    {
        res = false;
    }
    else
    {
        // update buffer with write data
        buffer[writeIndex] = data;
        // Shift write index
        writeIndex++;
        writeIndex %= cap;
        res = true;
        size++;
    }
    return res;
}