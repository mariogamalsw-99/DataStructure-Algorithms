#ifndef NODE_DUO_H
#define NODE_DUO_H
#include "double linked list.h"

template <typename T>
class NodeDou
{
private:
public:
    T data;
    NodeDou<T> *next;
    NodeDou<T> *prev;

    NodeDou();
    NodeDou(T userdata);
   
};

//____________________Double Node Class functions______________________
template <typename T>
NodeDou<T>::NodeDou() : next(nullptr), prev(nullptr)
{
}

template <typename T>
NodeDou<T>::NodeDou(T d) : next(nullptr), prev(nullptr), data(d)
{
};

#endif