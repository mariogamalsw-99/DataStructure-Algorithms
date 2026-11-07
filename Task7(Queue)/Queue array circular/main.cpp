#include "Queue.h"
#include <iostream>

int main(void)
{
    myQueue tstqueue{};
    tstqueue.enqueue(1);
    tstqueue.enqueue(2);
    tstqueue.enqueue(3);
    tstqueue.enqueue(4);
    int x=99;
    while(!tstqueue.isEmpty())
    {
        tstqueue.dequeue(x);
        std::cout<<x<<" ,";
    }
    std::cout<<std::endl;
    return 0;
}