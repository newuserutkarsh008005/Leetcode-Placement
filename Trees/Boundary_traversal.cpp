#include<iostream>
#include<vector>
using namespace std;
class Tree{
    public:
    int val;
    Tree * left=nullptr;
    Tree * right=nullptr;


};
Tree * insert(vector<int>& arr,int i){
    Tree * root =new Tree();
   
        root->val=arr[i];
        if(2*i+1<20)root->left=insert(arr,2*i+1);
        if(2*i+2<20)root->right=insert(arr,2*i+2);
     
    return root;
}
bool isChild(Tree * root){
    if(root->left==nullptr && root->right==nullptr){
        return true;
    }
    return false;
}
void left(vector<int>& data,Tree * root){
    Tree * node=root->left;
    while(node){
        if(!isChild(node))data.push_back(node->val);
        if(node->left)node=node->left;
        else node=node->right;
    }
}
void right(vector<int> & data,Tree * root){
    vector<int>temp;
    Tree * node=root->right;
    while(node){
        if(!isChild(node))temp.push_back(node->val);
        if(node->right)node=node->right;
        else node=node->left;
    }
    for(int i=temp.size()-1;i>=0;i--){
        data.push_back(temp[i]);
    }
}
void leaves(vector<int> & data , Tree * root){
if(root==nullptr)return ;
    if(isChild(root)){data.push_back(root->val);
        return ;
    }
    leaves(data,root->left);
    leaves(data,root->right);
}
vector<int> Boundary(Tree * root){
    vector<int>data;
    if(root==nullptr)return data;
    if(!isChild(root)) data.push_back(root->val);
    left(data,root);
    leaves(data,root);
    right(data,root);
    return data;
}
int main(){
vector<int> arr={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
Tree * root=insert(arr,0);
cout<<root->val;
vector<int>data=Boundary(root);
for(int i=0;i<data.size();i++){
    cout<<data[i]<<" ";
}


    return 0;

}