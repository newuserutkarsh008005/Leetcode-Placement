#include<iostream>
#include<map>

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
vector<int>topView(Tree * root){
    queue< pair<Tree * ,int>>q;
    map<int,int>mp;
    q.push({root,0});
    while(!q.empty()){
    auto it=q.front();
    q.pop();
    Tree * node=it.first;
    int x=it.second;
    if(mp.find(x)==mp.end())mp[x]=node->val;

        if(node->left)q.push({node->left,x-1});
         if(node->right)q.push({node->right,x+1});
   }
   //
   vector<int>ans;
   for(auto & it:mp){
    ans.push_back(it.second);
   }
   return ans;

}
int main(){
        vector<int>arr={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
        Tree * root=insert(arr,0);
        vector<int>ans=topView(root);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
    return 0;
}