#include <stdio.h>
#define SiZE 10
typedef struct 
{
    int arr[SiZE];
    int f;
    int r;
    int size;
}Queue_t;

Queue_t CreateQueue()
{
    Queue_t myque;
    myque.f=0;
    myque.r=0;
    myque.size=0;
    return myque;
}

bool isEmpty(Queue_t q)
{
    return(q.f==q.r);
}
bool isFull(Queue_t q)
{
    return q.size==SiZE;
}
bool enqueue(Queue_t q, int data)
{
    bool res=1;
    if(isFull(q))
    {
        res=0;
    }
    else
    {
        q.arr[q.r]=data;
        q.r++;
        q.r%=SiZE;
        q.size++;
    }
    return res;
}
int dequeue(Queue_t q)
{
    int res=-1;
    if(isEmpty(q))
    {
        res=-1;
    }
    else
    {
        res=q.arr[q.f];
        q.f++;
        q.f%=SiZE;
        q.size--;
    }
    return res;
}

int getFront(Queue_t q)
{
    if(isEmpty(q))
    {
        return -1;
    }
    else
    {
        return q.arr[q.f];
    }
}   
int getRear(Queue_t q)
{
    if(isEmpty(q))
    {
        return -1;
    }
    else
    {
        return q.arr[q.r];
    }
}
