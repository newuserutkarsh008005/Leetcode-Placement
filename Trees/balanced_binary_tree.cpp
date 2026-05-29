#include<iostream>
using namespace std;
class Tree{
public:
int val;
Tree* left;
Tree * right;
};
Tree * insert(vector<int>& arr, int i){
    if(i>=arr.size())return nullptr;
    Tree * node=new Tree();
    node->val=arr[i];
    node->left=insert(arr,2*i+1);
    node->right=insert(arr,2*i+2);
    return node;
}
int maxmdepth(Tree *node){
    if(node==nullptr)return 0;
    int lh=maxmdepth(node->left);
    int rh=maxmdepth(node->right);
    if(lh ==-1 || rh ==-1) return -1;
    if(abs(lh-rh)>1)return -1;
    return 1+ max(lh,rh);
}
int main(){
    Tree* root = new Tree();
root->val = 1;

root->left = new Tree();
root->left->val = 2;

root->left->left = new Tree();
root->left->left->val = 3;

root->left->left->left = new Tree();
root->left->left->left->val = 4;

root->right = nullptr;
if(maxmdepth(root)!=-1)cout<<"Balanced"<<endl;
else cout<<"Not Balanced";
    return 0 ;

}