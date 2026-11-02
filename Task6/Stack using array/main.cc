#include <iostream>
#include <string>
#include "StackArr.h"

int main()
{
    StackArr<int> intStack;
    intStack.push(1); 
    intStack.push(5); 
    intStack.push(6);
    while (!intStack.empty())
    {
        std::cout<<intStack.peek()<<std::endl;
        intStack.pop();

    }
    StackArr<std::string> strStack;
    strStack.push("Reversed!!"); 
    strStack.push("World "); 
    strStack.push("Hello ");
    while (!strStack.empty())
    {
        std::cout<<strStack.peek()<<std::endl;
        strStack.pop();

    }
     
    return 0;
}