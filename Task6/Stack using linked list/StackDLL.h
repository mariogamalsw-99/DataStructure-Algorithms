#ifndef STACK_DLL_H
#define STACK_DLL_H
#include "double linked list.h"

template <typename T>
class StackDLL
{
private:
    DoublelinkedList<T> Dll;

public:
    StackDLL();
    StackDLL(T arr[], int size);
    void push(T data);
    void pop();
    T peek();
    unsigned int size();
    bool empty();
};

//____________________Double Node Class functions______________________
template <typename T>
StackDLL<T>::StackDLL():Dll()
{
}
template <typename T>
StackDLL<T>::StackDLL(T arr[], int size):Dll(arr,size)
{
}
template <typename T>
void StackDLL<T>::push(T data)
{
    Dll.insertFront(data);
}

template <typename T>
void StackDLL<T>::pop()
{
    Dll.deleteFront();
}
template <typename T>
T StackDLL<T>::peek()
{
   return Dll.getFront();
}
template <typename T>
unsigned int StackDLL<T>::size()
{
    return  Dll.size();
}
template <typename T>
bool StackDLL<T>::empty()
{
   return Dll.empty();
}



#endif