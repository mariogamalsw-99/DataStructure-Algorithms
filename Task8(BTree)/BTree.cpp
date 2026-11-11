#include "BTree.h"
#include <queue>
#include <iostream>

void printDFSPreorderSubTree(TreeNode* head)
{
    if(head!=nullptr)
    {
        std::cout<<head->data<<",";
        printDFSPreorderSubTree(head->left);
        printDFSPreorderSubTree(head->right);
    }
}
void printDFSInorderSubTree(TreeNode* head)
{
    if(head!=nullptr)
    {
        printDFSInorderSubTree(head->left);
        std::cout<<head->data<<",";
        printDFSInorderSubTree(head->right);
    }
}
void printDFSPostorderSubTree(TreeNode* head)
{
    if(head!=nullptr)
    {
        printDFSPostorderSubTree(head->left);
        printDFSPostorderSubTree(head->right);
        std::cout<<head->data<<",";
    }
}
int countDFSPostorderSubTree(TreeNode* head)
{
    int res=0;
       if(head!=nullptr)
       {
           res+=countDFSPostorderSubTree(head->left);
           res+=countDFSPostorderSubTree(head->right);
           res++;
           return res;
       }
       else
       {
           return 0;
       }

}
int countLeafDFSPostorderSubTree(TreeNode* head)
{
    int res=0;
       if(head!=nullptr)
       {
           res+=countLeafDFSPostorderSubTree(head->left);
           res+=countLeafDFSPostorderSubTree(head->right);
           if(head->left == nullptr && head->right == nullptr)
             res++;
           return res;
       }
       else
       {
           return 0;
       }

}

void CleanSubTree(TreeNode* head)
{
       if(head!=nullptr)
       {
           CleanSubTree(head->left);
           CleanSubTree(head->right);
          // std::cout<<"Clean "<<head->data<<std::endl;
            delete head;
       }
       else
       {

       }

}



BTree::BTree()
{
    std::queue<TreeNode *> myqueue;
    char data;
    std::cout << "enter root data:";
    std::cin >> data;
    if (data == '0')
    {
        std::cout << "user create empty tree" << std::endl;
    }
    else
    {
        root->data = data;
        myqueue.push(root);
        TreeNode *temp;
        while (!myqueue.empty())
        {
            temp = myqueue.front();
            myqueue.pop();
            // left child
            std::cout << "enter left child of ( " << temp->data << " ) : ";
            std::cin >> data;
            if (data == '0')
            {
                std::cout << "No left child for ( " << temp->data << " )" << std::endl;
            }
            else
            {
                TreeNode *newleft = new TreeNode();
                newleft->data = data;
                temp->left = newleft;
                myqueue.push(newleft);
            }
            // right child
            std::cout << "enter right child of ( " << temp->data << " ) : ";
            std::cin >> data;
            if (data == '0')
            {
                std::cout << "No right child for ( " << temp->data << " )" << std::endl;
            }
            else
            {
                TreeNode *newright = new TreeNode();
                newright->data = data;
                temp->right = newright;
                myqueue.push(newright);
            }
        }
    }
}
BTree::~BTree()
{
    CleanSubTree(root);
}
int BTree::countNodes()
{
    
    return countDFSPostorderSubTree(root);

}
int BTree::countLeafNodes()
{

    return countLeafDFSPostorderSubTree(root);
}

void BTree::printBFS()
{
        std::queue<TreeNode *> myqueue;

    if (root == nullptr)
    {
        std::cout << "user create empty tree" << std::endl;
    }
    else
    {
        myqueue.push(root);
        TreeNode *temp;
        while (!myqueue.empty())
        {
            temp = myqueue.front();
            myqueue.pop();
            std::cout << temp->data << ",";
            // left child
            if (temp->left != nullptr)
            {
                myqueue.push(temp->left);
            }
            // right child
            if (temp->right != nullptr)
            {
                myqueue.push(temp->right);
            }
        }
    }
}
void BTree::printDFSPreorder()
{
    printDFSPreorderSubTree(root);
}
void BTree::printDFSInorder()
{
    printDFSInorderSubTree(root);
    
}
void BTree::printDFSPostorder()
{
    printDFSPostorderSubTree(root);
    
}


