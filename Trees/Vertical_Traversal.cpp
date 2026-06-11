/*
VERTICAL TRAVERSAL

Data Structure:
map<int, map<int, multiset<int>>> nodes;

column (x) -> row (y) -> sorted node values

-------------------------------------------------

1) BFS Traversal

queue<pair<Tree*, pair<int,int>>> q;

Store:
(node, {column, row})

Root:
column = 0
row = 0

Left Child:
(column - 1, row + 1)

Right Child:
(column + 1, row + 1)

For every node:

nodes[column][row].insert(node->val);

Why multiset?
- Multiple nodes can have the same (column,row).
- Values must appear in sorted order.

-------------------------------------------------

2) Build Answer

for each column in nodes:

    vector<int> temp;

    for each row in that column:

        append all values from multiset
        into temp

    ans.push_back(temp);

Since:
- outer map sorts columns (left -> right)
- inner map sorts rows (top -> bottom)
- multiset sorts values at same position

The resulting answer is already in the required order.

-------------------------------------------------

3) Return ans

Time Complexity:
O(N log N)

*/


#include<iostream>
#include<vector>
#include <map>
#include <queue>
#include <set>
using namespace std;
class Tree{
    public:
    int val;
    Tree * left=nullptr;
    Tree * right=nullptr;
};

Tree * insert(vector<int>& arr,int i){
    Tree * node=new Tree();
    node->val=arr[i];
    if(2*i+1<arr.size())node->left=insert(arr,2*i+1);
    if(2*i+2<arr.size())node->right=insert(arr,2*i+2);
return node;
}
vector<vector<int>> vertical(Tree * node){
    queue<pair<Tree * ,pair<int,int>>> q;
    map<int,map<int,multiset<int>>>t;
    q.push({node,{0,0}});
    
    //Traversal BFS for the Tree 
    while(!q.empty()){
        auto p=q.front();
        q.pop();
        Tree * temp=p.first;
        int x=p.second.first;
        int y=p.second.second;
        t[x][y].insert(temp->val);
        if(temp->left){
            q.push({temp->left,{x-1,y+1}});
        }
         if(temp->right){
            q.push({temp->right,{x+1,y+1}});
        }

    }
    // insertion in the ans;
    vector<vector<int>> ans;
    for(auto a:t){
        vector<int>temp;
        for(auto b:a.second){
            temp.insert(temp.end(),b.second.begin(),b.second.end());
        }
        ans.push_back(temp);
    }
    return ans;
}
int main(){
vector<int>arr={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
Tree * root=insert(arr,0);
vector<vector<int>> ans=vertical(root);
for (int i = 0; i < ans.size(); i++){
for(int j=0;j<ans[i].size();j++){
    cout<<ans[i][j] <<" ";
}
cout<<endl;
}

    return 0;
}