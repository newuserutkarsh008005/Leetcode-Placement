#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Tree{
    public:
    int val;
    Tree * left=nullptr;
    Tree * right=nullptr;

};

Tree * insert(vector<int> & arr,int i){
if(i>=arr.size())return nullptr;
    Tree * root=new Tree();
    root->val=(arr[i]);
    root->left=insert(arr,(2*i)+1);

     root->right=insert(arr,(2*i)+2);
     return root;

}
void traversal(Tree * head){
    if(head==nullptr)return ;
    cout<<head->val<<"--";
    traversal(head->left);
    traversal(head->right);
}
vector<vector<int>> bfs (Tree * head){
   if(head==nullptr)return {};
vector<vector<int>>ans;

queue<Tree *>q;
q.push(head);
while(!q.empty()){
    int sz=q.size();
    vector<int>lvl;
    for(int i=0;i<sz;i++){
        Tree * valu=q.front();
        q.pop();
        if(valu->left!=nullptr)q.push(valu->left);
        if(valu->right!=nullptr)q.push(valu->right);
        lvl.push_back(valu->val);
    }
    ans.push_back(lvl);
}

return ans;
}
vector<int>preorderd(Tree * root){
    vector<int>value;
    if(root==nullptr)return value;
    stack<Tree *>st;
    st.push(root);
    while(!st.empty()){
        root=st.top();
        st.pop();
        value.push_back(root->val);
        if(root->right!=nullptr) st.push(root->right);
        if(root->left!=nullptr) st.push(root->left);
    }
    return value;
}
vector<int>postorderd(Tree * root){
    vector<int>value;
    if(root==nullptr)return value;
    stack<Tree *>st;
    st.push(root);
    while(!st.empty()){
        root=st.top();
        st.pop();
       
        if(root->right!=nullptr) st.push(root->left);
        if(root->left!=nullptr) st.push(root->right);
         value.push_back(root->val);
    }
    return value;
}
int main(){
vector<int> arr={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
Tree * root=new Tree();
root=insert(arr,0);
traversal(root);
cout<<endl;
vector<vector<int>>value=bfs(root);
for(int i=0;i<value.size();i++){
    cout<<"Level"<<i+1 <<":  ";
    for(int j=0;j<value[i].size();j++){
        cout<<value[i][j]<<" ";
    }
    cout<<endl;
}

vector<int>pre=preorderd(root);
for(int i=0;i<pre.size();i++){
    cout<<pre[i]<<"-";
}
cout<<endl;
vector<int>pos=postorderd(root);
for(int i=0;i<pos.size();i++){
    cout<<pos[i]<<"-";
}
    return 0;
}