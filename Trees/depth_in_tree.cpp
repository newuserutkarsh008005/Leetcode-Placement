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
    return 1+ max(lh,rh);
}
int main(){
     vector<int>arr={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
Tree * root=insert(arr,0);
cout<<maxmdepth(root);
    return 0 ;

}