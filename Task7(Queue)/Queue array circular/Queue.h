#ifndef QUEUE_H
#define QUEUE_H 

class myQueue
{
private:
    unsigned int readIndex;
    unsigned int writeIndex;
    unsigned int cap;
    unsigned int size;
    int *buffer;

public:
    myQueue();
    ~myQueue();
    // User Interface
    bool dequeue(int &data);
    bool enqueue(int data);
    bool isEmpty();
    bool isFull();
};

#endif