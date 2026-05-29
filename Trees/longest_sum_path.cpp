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
     vector<int>arr={123451,123452,123453,123454,123455,123456,123457,123458,123459,1123450,1123451,1123452,1123453,1123454,1123455,1123456,1123457,1123458,1123459,2123450,2123451,2123452,2123453,2123454,2123455,2123456,2123457,2123458,2123459,3123450};
Tree * root=insert(arr,0);
int dia=0;
longestpath(root,dia);
cout<<dia;
    return 0 ;

}