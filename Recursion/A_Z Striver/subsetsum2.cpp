#include<iostream>
#include<set>
using namespace std;

class Solution {
public:
set<vector<int>> s;
void allsubset(vector<vector<int>> & ans,vector<int> & a1,vector<int>&nums,int i){
   //base case
    if(i==nums.size()){
        if(s.find(a1)==s.end()){
            ans.push_back(a1);
            s.insert(a1);

        }
        return;
    }
    //take
    a1.push_back(nums[i]);
    allsubset(ans,a1,nums,i+1);
    a1.pop_back();
    //backtrack
    allsubset(ans,a1,nums,i+1);

}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       vector< vector<int>> ans;
       vector<int>a1;
       sort(nums.begin(),nums.end());
allsubset(ans,a1,nums,0);
return ans;
    }
};