#include<iostream>
using namespace std;
class Tree{
public:
int val;
Tree * left=nullptr;
Tree * right=nullptr;
};
Tree * insert(vector<int> & arr ,int i){
    if(i>=arr.size())return nullptr;
    Tree * root=new Tree();
    root->val=arr[i];
    root->left=insert(arr,2*i+1);
    root->right=insert(arr,2*i+2);
    return root;
}

vector<vector<int>>bfs(Tree * root){
    if (root==nullptr)return {} ;
    vector<vector<int>>ans;
    queue<Tree *>q;
    q.push(root);
    while(!q.empty()){
        int sz=q.size();
        vector<int>lvl;
        for(int i=0;i<sz;i++){
            Tree * valu=q.front();
            q.pop();
            if(valu->left != nullptr)
                q.push(valu->left);

            if(valu->right != nullptr)
                q.push(valu->right);
            lvl.push_back(valu->val);
        }
ans.push_back(lvl);
    }
    return ans;
}

int main(){
    vector<int>arr={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    Tree * head=new Tree();
    head=insert(arr,0);
    vector<vector<int>> ans=bfs(head);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<< " ";
        }
        cout<<endl;
    }
    return 0;
}