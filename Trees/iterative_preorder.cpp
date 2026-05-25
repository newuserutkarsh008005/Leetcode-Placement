#include<iostream>
#include<vector>
#include<stack>

using namespace std;
class Tree{
public:
int val;
Tree * left;
Tree * right;

};
Tree * insert(vector<int> & arr,int i){
    if(i>=arr.size())return nullptr;
    Tree* node=new Tree();
    node->val=arr[i];
    node->left=insert(arr,2*i+1);
    node->right=insert(arr,2*i +2);
    return node;
}
void printing(vector<int>&val){
    for(int i=0;i<val.size();i++){
        cout<<val[i]<<"->";
    }
    cout<<endl;
}
void preorder (Tree * node){
    vector<int>value;
    stack<Tree * >st;
    st.push(node);
    while(!st.empty()){
        node=st.top();
        st.pop();
        value.push_back(node->val);
        if(node->right!=nullptr)st.push(node->right);
        if(node->left!=nullptr)st.push(node->left);
    }
printing(value);

}
void postorder(Tree * node){
    vector<int>value;
    stack<Tree * >st1,st2;
    Tree * root=node;
    st1.push(root);
    while(!st1.empty()){
        root=st1.top();
        st1.pop();
        st2.push(root);
        if(root->left!=nullptr)st1.push(root->left);
        if(root->right!=nullptr)st1.push(root->right);

    }
    while(!st2.empty()){
        root=st2.top();
        st2.pop();
        value.push_back(root->val);
    }
    printing(value);
}
void inorder(Tree * node){
    vector<int>value;
    Tree * root=node;
    stack<Tree *>st;

    while(true){
        if(root!=nullptr){
            st.push(root);
            root=root->left;

        }
        else{
            if(st.empty()==true)break;
            root=st.top();
            st.pop();
            value.push_back(root->val);
            root=root->right;
        }
    }
    printing(value);
}
int main(){
    vector<int>arr={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    Tree * node=insert(arr,0);
    preorder(node);
    postorder(node);
    inorder(node);
    return 0;

}