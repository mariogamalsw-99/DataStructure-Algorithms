#include <iostream>
#include "StackDLL.h"

int main()
{
    StackDLL<int> intStack;
    intStack.push(1); 
    intStack.push(5); 
    intStack.push(6);
    while (!intStack.empty())
    {
        std::cout<<intStack.peek()<<std::endl;
        intStack.pop();

    }
     
    return 0;
}