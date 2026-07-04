#include <iostream>
#include <algorithm>

using namespace std;

class TreeNode{
public:

    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){
        val=x;
        left=right=nullptr;
    }
};

int diameter=0;

int depth(TreeNode* root){

    if(root==nullptr)
        return 0;

    int left=depth(root->left);
    int right=depth(root->right);

    diameter=max(diameter,left+right);

    return 1+max(left,right);
}

int main(){

    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);

    depth(root);

    cout<<diameter;

    return 0;
}