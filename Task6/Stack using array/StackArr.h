#ifndef STACK_ARR_H
#define STACK_ARR_H
#include "Myarray.h"

template <typename T>
class StackArr
{
private:
    MYArray<T> arr;

public:
    StackArr();
    void push(T data);
    void pop();
    T peek();
    unsigned int size();
    bool empty();
};

//____________________Double Node Class functions______________________
template <typename T>
StackArr<T>::StackArr():arr(0,5)
{
}
template <typename T>
void StackArr<T>::push(T data)
{
    arr.add(data);
}

template <typename T>
void StackArr<T>::pop()
{
    arr.remove(arr.getSize()-1);
}
template <typename T>
T StackArr<T>::peek()
{
   return arr.get(arr.getSize()-1);
}
template <typename T>
unsigned int StackArr<T>::size()
{
    return  arr.getSize();
}
template <typename T>
bool StackArr<T>::empty()
{
   return (arr.getSize()==0);
}



#endif