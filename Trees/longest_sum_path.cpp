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

int longestpath(Tree *node,int  & dia){
    if(node==nullptr)return 0;
    int lh=max(0,longestpath(node->left,dia));
    int rh=max(0,longestpath(node->right,dia));
    dia=max(dia,lh+rh+node->val);
    return node->val+ max(lh,rh);
}
int main(){
     vector<int>arr={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
Tree * root=insert(arr,0);
int dia=0;
longestpath(root,dia);
cout<<dia;
    return 0 ;

}