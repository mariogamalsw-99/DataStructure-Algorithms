#include "double linked list.h"
#include <iostream>
#include <string>
#include "double linked list.h"
int main()
{
    int iarr[]={2,4,523,23,25,92,-3};
    std::string strarr[]={"hello","world","from","linked","list"};
    DoublelinkedList<int> dllint(iarr,7);
    DoublelinkedList<std::string> dllstr(strarr,5);
    dllint.display();
    std::cout<<"min of list: "<<dllint.min()<<std::endl;
    std::cout<<"max of list: "<<dllint.max()<<std::endl;
    std::cout<<"cont of list: "<<dllint.count(2)<<std::endl;
    std::cout<<"sum of list: "<<dllint.sum()<<std::endl;
    dllstr.display();
    dllstr.deleteFront();
    dllstr.remove(2);
    dllstr.display();
    dllstr.insertFront("__HELLO__");
    dllstr.insertBack(",_MARIO_");
    dllstr.insert("DOUBLE",3);
    dllstr.insert("??*",1);
    dllstr.insert("LINKED",5);
    dllstr.display();

    std::cout<<"size of string linked list"<<dllstr.size();


    return 0;
}