#include "BSTree.h"
#include <queue>
#include <iostream>

void printDFSPreorderSuBSTree(TreeNode *head)
{
    if (head != nullptr)
    {
        std::cout << '|' << head->data << '|' << ",";
        printDFSPreorderSuBSTree(head->left);
        printDFSPreorderSuBSTree(head->right);
    }
}
void printDFSInorderSuBSTree(TreeNode *head)
{
    if (head != nullptr)
    {
        printDFSInorderSuBSTree(head->left);
        std::cout << '|' << head->data << '|' << ",";
        printDFSInorderSuBSTree(head->right);
    }
}
void printDFSPostorderSuBSTree(TreeNode *head)
{
    if (head != nullptr)
    {
        printDFSPostorderSuBSTree(head->left);
        printDFSPostorderSuBSTree(head->right);
        std::cout << '|' << head->data << '|' << ",";
    }
}
int countDFSPostorderSuBSTree(TreeNode *head)
{
    int res = 0;
    if (head != nullptr)
    {
        res += countDFSPostorderSuBSTree(head->left);
        res += countDFSPostorderSuBSTree(head->right);
        res++;
        return res;
    }
    else
    {
        return 0;
    }
}
int countLeafDFSPostorderSuBSTree(TreeNode *head)
{
    int res = 0;
    if (head != nullptr)
    {
        res += countLeafDFSPostorderSuBSTree(head->left);
        res += countLeafDFSPostorderSuBSTree(head->right);
        if (head->left == nullptr && head->right == nullptr)
            res++;
        return res;
    }
    else
    {
        return 0;
    }
}
TreeNode *insertNodeInSubTree(TreeNode *root, int data)
{
    if (root == nullptr)
    {
        return new TreeNode(data);
    }
    else if (data <= root->data)
    {
        root->left = insertNodeInSubTree(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertNodeInSubTree(root->right, data);
    }
    return root;
}
TreeNode *searchSubTree(TreeNode *root, int key)
{
    if (root == nullptr)
    {
        return root;
    }
    if (root->data == key)
    {
        return root;
    }
    else if (key < root->data)
    {
        return searchSubTree(root->left, key);
    }
    else
    {
        return searchSubTree(root->right, key);
    }
}
TreeNode *getPredessorSubTree(TreeNode *root)
{
    if (root == nullptr)
    {
        return root;
    }
    while (root->right)
    {
        root = root->right;
    }
    return root;
}
TreeNode* deleteNodeSubTree(TreeNode* root,int key)
{
    if(root == nullptr)
    {
        return nullptr;
    }
    if(key< root->data)
    {
        root->left = deleteNodeSubTree(root->left,key);
    }
    else if(key> root->data)
    {
        root->right = deleteNodeSubTree(root->right,key);
    }
    else
    {
        if(root->left == nullptr && root->right == nullptr)
        {
            free(root);
            return nullptr;
        }
        else if(root->left == nullptr)
        {
            TreeNode* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right == nullptr)
        {
            TreeNode* temp=root->left;
            free(root);
            return temp;
        }
        else
        {
            TreeNode* pre = getPredessorSubTree(root->left);
            root->data=pre->data;
            root->left=deleteNodeSubTree(root->left,pre->data);
        }
    }
    return root;
}

void CleanSuBSTree(TreeNode *head)
{
    if (head != nullptr)
    {
        CleanSuBSTree(head->left);
        CleanSuBSTree(head->right);
        std::cout<<"Clean "<<head->data<<std::endl;
        delete head;
    }
}

void BSTree::insertNode(int data)
{
    root = insertNodeInSubTree(root, data);
}
void BSTree::deleteNode(int key)
{
    root = deleteNodeSubTree(root,key);
}

BSTree::BSTree()
{
    std::queue<TreeNode *> myqueue;
    int data;
    std::cout << "enter root data:";
    std::cin >> data;
    if (data == 0)
    {
        std::cout << "user create empty tree" << std::endl;
    }
    else
    {
        root = new TreeNode(data);
        myqueue.push(root);
        TreeNode *temp;
        while (!myqueue.empty())
        {
            temp = myqueue.front();
            myqueue.pop();
            // left child
            std::cout << "enter left child of ( " << temp->data << " ) : ";
            std::cin >> data;
            if (data == 0)
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
            if (data == 0)
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
BSTree::~BSTree()
{
    CleanSuBSTree(root);
}
int BSTree::countNodes()
{

    return countDFSPostorderSuBSTree(root);
}
int BSTree::countLeafNodes()
{

    return countLeafDFSPostorderSuBSTree(root);
}

void BSTree::printBFS()
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
        int c = 0,
            l = 1;
        while (!myqueue.empty())
        {
            c++;

            temp = myqueue.front();
            myqueue.pop();
            if (temp == nullptr)
            {
                std::cout << '|' << "__" << '|' << ",";
            }
            else
            {
                std::cout << '|' << temp->data << '|' << ",";
                // left child

                myqueue.push(temp->left);

                // right child

                myqueue.push(temp->right);
            }
            if (c == l)
            {
                std::cout << std::endl;
                c = 0;
                l *= 2;
            }
        }
    }
}
void BSTree::printDFSPreorder()
{
    printDFSPreorderSuBSTree(root);
}
void BSTree::printDFSInorder()
{
    printDFSInorderSuBSTree(root);
}
void BSTree::printDFSPostorder()
{
    printDFSPostorderSuBSTree(root);
}
