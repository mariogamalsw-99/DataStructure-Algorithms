#include "BTree.h"
#include <iostream>
int main()
{
    BTree myTree;
    std::cout<<"_________the tree BFS________"<<std::endl;
    myTree.printBFS();
    std::cout<<std::endl;
    std::cout<<"_________the tree DFS Preordre________"<<std::endl;
    myTree.printDFSPreorder();
    std::cout<<std::endl;
    std::cout<<"_________the tree DFS Inorder________"<<std::endl;
    myTree.printDFSInorder();
    std::cout<<std::endl;
    std::cout<<"_________the tree DFS PostOrder________"<<std::endl;
    myTree.printDFSPostorder();
    std::cout<<std::endl;
    std::cout<<"num of nodes: "<<myTree.countNodes()<<std::endl<<"num of leafs: "<<myTree.countLeafNodes()<<std::endl;
    return 0;
}