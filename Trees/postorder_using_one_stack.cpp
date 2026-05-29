#include<iostream>
#include<vector>
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
vector<vector<int>>bfs(Tree * node){
    vector<vector<int>>ans;
    queue<Tree *>q;
    q.push(node);
    while(!q.empty()){
        int sz=q.size();
        vector<int>tem;

        Tree * temp=new Tree();
        for(int i=0;i<sz;i++){
            temp=q.front();
            q.pop();
            if(temp->left!=nullptr)q.push(temp->left);
            if(temp->right!=nullptr)q.push(temp->right);
            tem.push_back(temp->val);
        }
        ans.push_back(tem);

       
    }
    return ans;
}
vector<int> postorder(Tree * node){
    vector<int>post;
    stack<Tree * >st;
    Tree * temp=nullptr;
    while(node || !st.empty()){
        if(node!=nullptr){
            st.push(node);
            node=node->left;
        }
        else{
          temp=st.top()->right;
        if(temp==nullptr){
            temp=st.top();
            st.pop();
            post.push_back(temp->val);
            while(!st.empty() && temp==st.top()->right){
                temp=st.top();
                st.pop();
                post.push_back(temp->val);

            }

        }
        else{
            node=temp;
        }
        }
    }
    return post;
}
int main(){
vector<int>arr={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
Tree * root=insert(arr,0);
vector<vector<int>>ans=bfs(root);
for(int i=0;i<ans.size();i++){
    cout<<"Level "<<i+1<<" : ";
    for(int j=0;j<ans[i].size();j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
}
vector<int>post=postorder(root);
for(int i=0;i<post.size();i++){
    cout<<post[i]<<" ";
}
    return 0;

}