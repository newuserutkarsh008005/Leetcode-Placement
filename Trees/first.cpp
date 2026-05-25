#include<iostream>
#include<vector>
using namespace std;
class Tree{
public:
int val;
Tree*left=nullptr;
Tree*right=nullptr;

};

Tree *insert(vector<int> & arr , int i ){
    if(i>=arr.size())return nullptr;
    Tree * root=new Tree();
    root->val=arr[i];
    root->left=insert(arr,2*i+1);
    root->right=insert(arr,2*i+2);
    return root;
}



void prtraversal(Tree * root){
    if(root==nullptr)return ;
        cout<<root->val<<"--";
        prtraversal(root->left);
        prtraversal(root->right);
    
}
void potraversal(Tree *root){
    if(root==nullptr)return ;
    potraversal(root->left);
    potraversal(root->right);
    cout<<root->val<<"--";
}
void inorder(Tree * root){
    if(root==nullptr) return ;
    inorder(root->left);
    cout<<root->val<<"--";
    inorder(root->right);
}
int main(){
    vector<int> arr={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    Tree * head=insert(arr,0);
    prtraversal(head);
    cout<<endl;
    potraversal(head);
    cout<<endl;
    inorder(head);
    return 0;
}