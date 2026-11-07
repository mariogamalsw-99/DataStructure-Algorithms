class TreeNode{
    public:
    TreeNode* left;
    TreeNode* right;
    char data;
};

class BTree{
    public:
    BTree();
    ~BTree();
    int countNodes();
    int countLeafNodes();
    void printBFS();
    void printDFSPreorder();
    void printDFSInorder();
    void printDFSPostorder();
    private:
    TreeNode* root;

};

