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

int main(){
    vector<int>arr={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
Tree * root=insert(arr,0);

vector<int>pre;
vector<int>post;
vector<int>in;
stack<pair<Tree *,int >>st;
st.push({root,1});
while(!st.empty()){
    auto it=st.top();
    st.pop();
    if(it.second==1){
        pre.push_back(it.first->val);
        it.second++;
        st.push(it);
        if(it.first->left!=nullptr){
            st.push({it.first->left,1});
        }
    }
    else if(it.second==2){
        in.push_back(it.first->val);
        it.second++;
        st.push(it);
         if(it.first->right!=nullptr){
            st.push({it.first->right,1});
        }
    }
    else{
post.push_back(it.first->val);
    }
}
for(int i=0;i<arr.size();i++){
   cout<< pre[i]<<" ";
}
cout<<endl;
for(int i=0;i<arr.size();i++){
   cout<< in[i]<<" ";
}
cout<<endl;
for(int i=0;i<arr.size();i++){
   cout<< post[i]<<" ";
}

    return 0;
}