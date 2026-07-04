#include <iostream>

using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){
        val = x;
        left = right = nullptr;
    }
};

TreeNode* invertTree(TreeNode* root){

    if(root == nullptr)
        return nullptr;

    swap(root->left, root->right);

    invertTree(root->left);
    invertTree(root->right);

    return root;
}

void preorder(TreeNode* root){

    if(root == nullptr)
        return;

    cout << root->val << " ";

    preorder(root->left);
    preorder(root->right);
}

int main(){

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    invertTree(root);

    preorder(root);

    return 0;
}