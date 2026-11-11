class TreeNode{
    public:
    TreeNode(int d):left(nullptr),right(nullptr),data(d){}
    TreeNode()=default;
    TreeNode* left;
    TreeNode* right;
    int data;
};

class BSTree{
    public:

    BSTree();
    ~BSTree();
    void insertNode(int data);
    void deleteNode(int key);
    int countNodes();
    int countLeafNodes();
    void printBFS();
    void printDFSPreorder();
    void printDFSInorder();
    void printDFSPostorder();
    private:
    TreeNode* root;

};

