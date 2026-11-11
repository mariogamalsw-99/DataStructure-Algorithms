#include "BSTree.h"
#include <iostream>
int main()
{
    BSTree myTree;
    myTree.insertNode(10);
    myTree.insertNode(1);
    myTree.insertNode(5);
    myTree.insertNode(90);
    std::cout<<"_________the tree BFS________"<<std::endl;
    myTree.printBFS();
    myTree.deleteNode(7);
    myTree.deleteNode(5);
    std::cout<<"_________the tree BFS________"<<std::endl;
    myTree.printBFS();
    std::cout<<std::endl;

    std::cout<<std::endl;
    std::cout<<"num of nodes: "<<myTree.countNodes()<<std::endl<<"num of leafs: "<<myTree.countLeafNodes()<<std::endl;
    return 0;
}