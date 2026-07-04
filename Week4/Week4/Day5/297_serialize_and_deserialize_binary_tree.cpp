#include <iostream>
#include <sstream>

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

string serialize(TreeNode* root){

    if(root==nullptr)
        return "#,";

    return to_string(root->val)+","+
           serialize(root->left)+
           serialize(root->right);
}

TreeNode* deserializeHelper(stringstream& ss){

    string val;

    getline(ss,val,',');

    if(val=="#")
        return nullptr;

    TreeNode* root=new TreeNode(stoi(val));

    root->left=deserializeHelper(ss);
    root->right=deserializeHelper(ss);

    return root;
}

TreeNode* deserialize(string data){

    stringstream ss(data);

    return deserializeHelper(ss);
}

int main(){

    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);

    string s=serialize(root);

    cout<<s<<endl;

    TreeNode* copy=deserialize(s);

    cout<<copy->val;

    return 0;
}