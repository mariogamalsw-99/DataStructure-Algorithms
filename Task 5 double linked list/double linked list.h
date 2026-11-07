#ifndef DOUBLE_LL_H
#define DOUBLE_LL_H
#include "nodedou.h"
#include <iostream>

template <typename T>
class DoublelinkedList
{
private:
    NodeDou<T> *head;
    NodeDou<T> *tail;
    unsigned int dllSize;

public:
    DoublelinkedList();
    ~DoublelinkedList();
    DoublelinkedList(T arr[], int size);
    bool empty();
    unsigned int size();
    void display();
    int count(T uData);
    T min();
    T max();
    T sum();
    void insert(T userData, int index);
    void insertBack(T userData);
    void insertFront(T userData);
    void remove(int index);
    void deleteBack();
    void deleteFront();
    T getFront();
    T getBack();
};
//____________________Double LinkedList Class functions______________________
template <typename T>
DoublelinkedList<T>::DoublelinkedList() : head(nullptr), tail(nullptr), dllSize(0)
{
}
template <typename T>
DoublelinkedList<T>::DoublelinkedList(T arr[], int size) : head(nullptr), tail(nullptr), dllSize(size)
{
    if (size > 0)
    {
        // add first node
        head = new NodeDou<T>(arr[0]);
        NodeDou<T> *temp = head;
        for (int i = 1; i < size; i++)
        {
            NodeDou<T> *newNode = new NodeDou<T>(arr[i]);
            newNode->prev = temp;
            temp->next = newNode;
            temp = newNode;
        }
        tail = temp;
    }
}
template <typename T>
DoublelinkedList<T>::~DoublelinkedList()
{
    NodeDou<T> *currNode = head;
    while (head != nullptr)
    {
        // shift head to next node then delete current node
        currNode = head;
        head = head->next;
        delete currNode;
    }
}
template <typename T>
bool DoublelinkedList<T>::empty()
{
    return (head == nullptr);
}
template <typename T>
unsigned int DoublelinkedList<T>::size()
{
    return dllSize;
}
template <typename T>
void DoublelinkedList<T>::display()
{
    NodeDou<T> *temp = head;
    while (temp != nullptr)
    {
        std::cout << "|" << temp->data << "|-> ";
        temp = temp->next;
    }
    std::cout << std::endl;
}
template <typename T>
int DoublelinkedList<T>::count(T uData)
{
    int c = 0;
    NodeDou<T> *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == uData)
        {
            c++;
        }
        temp = temp->next;
    }
    return c;
}
template <typename T>
T DoublelinkedList<T>::min()
{
    if (!empty())
    {
        NodeDou<T> *temp = head;
        T min = temp->data;
        while (temp != nullptr)
        {
            if (min > temp->data)
            {
                min = temp->data;
            }
            temp = temp->next;
        }
        return min;
    }
    else
    {
        return -1;
    }
}
template <typename T>
T DoublelinkedList<T>::max()
{
    if (!empty())
    {
        NodeDou<T> *temp = head;
        T max = temp->data;
        while (temp != nullptr)
        {
            if (max < temp->data)
            {
                max = temp->data;
            }
            temp = temp->next;
        }
        return max;
    }
    else
    {
        return -1;
    }
}
template <typename T>
T DoublelinkedList<T>::sum()
{
    if (!empty())
    {
        NodeDou<T> *temp = head;
        T sum = T();
        while (temp != nullptr)
        {
            sum += temp->data;
            temp = temp->next;
        }
        return sum;
    }
    else
    {
        return -1;
    }
}
template <typename T>
void DoublelinkedList<T>::insert(T userData, int index)
{
    if (index < 1)
    {
        insertFront(userData);
    }
    else if (index >= dllSize)
    {
        insertBack(userData);
    }
    else
    {
        NodeDou<T> *newNode = new NodeDou(userData);
        // decide which is faster from head and forward or from tail and backward
        unsigned int midIndex = dllSize / 2;
        if (index < midIndex)
        {
            // start form head
            NodeDou<T> *temp = head;
            for (int i = 0; i < index; i++)
            {
                temp = temp->next;
            }
            temp->prev->next = newNode;
            newNode->prev = temp->prev;
            temp->prev = newNode;
            newNode->next = temp;
        }
        else
        {
            // start from tail
            NodeDou<T> *temp = tail;
            for (int i = 1; i < (dllSize - index); i++)
            {
                temp = temp->prev;
            }
            temp->prev->next = newNode;
            newNode->prev = temp->prev;
            temp->prev = newNode;
            newNode->next = temp;
        }
        dllSize++;
    }
}
template <typename T>
void DoublelinkedList<T>::insertBack(T userData)
{
    NodeDou<T> *newNode = new NodeDou<T>(userData);
    if (!empty())
    {
        tail->next = newNode;
        newNode->prev = tail;
    }
    else
    {
        head = newNode;
    }
    tail = newNode;
    dllSize++;
}
template <typename T>
void DoublelinkedList<T>::insertFront(T userData)
{
    NodeDou<T> *newNode = new NodeDou<T>(userData);
    if (!empty())
    {
        newNode->next = head;
        head->prev = newNode;
    }
    head = newNode;
    dllSize++;
}
template <typename T>
void DoublelinkedList<T>::remove(int index)
{
    if (index < 1)
    {
        deleteFront();
    }
    else if (index >= dllSize)
    {
        deleteBack();
    }
    else
    {

        // decide which is faster from head and forward or from tail and backward
        unsigned int midIndex = dllSize / 2;
        if (index < midIndex)
        {
            // start form head
            NodeDou<T> *temp = head;
            for (int i = 0; i < index; i++)
            {
                temp = temp->next;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
        else
        {
            // start from tail
            NodeDou<T> *temp = tail;
            for (int i = 1; i < (dllSize - index); i++)
            {
                temp = temp->prev;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
        dllSize--;
    }
}
template <typename T>
void DoublelinkedList<T>::deleteBack()
{
    NodeDou<T> *deleteNode = tail;
    // Shift tail and clear tail next
    tail = tail->prev;
    if (tail != nullptr)
    {
        tail->next = nullptr;
    }
    else
    {
        head = nullptr;
    }
    delete deleteNode;
    dllSize--;
}
template <typename T>
void DoublelinkedList<T>::deleteFront()
{
    NodeDou<T> *deleteNode = head;
    // Shift head and clear head prev
    head = head->next;
    if (head != nullptr)
    {
        head->prev = nullptr;
    }
    else
    {
        tail = nullptr;
    }
    delete deleteNode;
    dllSize--;
}
template <typename T>
T DoublelinkedList<T>::getFront()
{
    if (!empty())
        return head->data;
    else
        return -1;
}
template <typename T>
T DoublelinkedList<T>::getBack()
{
    if (!empty())
        return tail->data;
    else
        return -1;
}

#endif