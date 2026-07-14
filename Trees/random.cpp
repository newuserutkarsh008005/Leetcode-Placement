#include<iostream>
#include<vector>
using namespace std;
class Tree{
public:
int val;
Tree * left=nullptr;
Tree * right=nullptr;
};




   bool isleaf(Tree *root){
    return root && root->left == nullptr && root->right == nullptr;
} 

void left(Tree * root,vector<int> & ans){
 stack<Tree * >st;
 st.push(root->left);
 while(!st.empty()){
    Tree * temp=st.top();
    st.pop();
    if(!isleaf(temp)){
        ans.push_back(temp->val);
        if(temp->left){
            st.push(temp->left);
        }
        else
            st.push(temp->right);
        
    }
 }


}
void right(Tree * root,vector<int> & ans){
 stack<Tree * >st;
 vector<int>second;
 st.push(root->right);
 while(!st.empty()){
    Tree * temp=st.top();
    st.pop();
    if(!isleaf(temp)){
        second.push_back(temp->val);
        if(temp->right){
            st.push(temp->right);
        }
       else 
            st.push(temp->left);
        
    }
    
 }
 for(int i=second.size()-1;i>=0;i--){
        ans.push_back(second[i]);
    }


}
void ino(Tree * root, vector<int> & ans){
    if(root== nullptr)return;
    if(isleaf(root))ans.push_back(root->val);
    ino(root->left,ans);
     ino(root->right,ans);
 }

vector<int>boundary(Tree * root){
    vector<int>ans;
    ans.push_back(root->val);
   left(root,ans);
   ino(root,ans);
   right(root,ans);
   return ans;
}


 Tree * insert(vector<int>& arr, int i){
    if(i>=arr.size())return nullptr;
    Tree * node=new Tree();
    node->val=arr[i];
    node->left=insert(arr,2*i+1);
    node->right=insert(arr,2*i+2);
    return node;
}
int main(){
    vector<int>arr={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
Tree * root=insert(arr,0);
vector<int>boun=boundary(root);
for(int i=0;i<boun.size();i++){
    cout<<boun[i]<<" ";
}
    return 0;
}