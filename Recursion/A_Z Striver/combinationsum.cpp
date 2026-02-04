#include<iostream>
using namespace std;


class Solution {
public:
void combsum(vector<vector<int>> &ans,vector<int> &a1,vector<int> &c,int i,int t){
//base case
if(t==0){
    ans.push_back(a1);
    return ;
}
if(i==c.size() || t<0){
    return ;
}
a1.push_back(c[i]);
combsum(ans,a1,c,i,t-c[i]);

a1.pop_back();
combsum(ans,a1,c,i+1,t);

}
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<vector<int> >ans;
        vector<int> a1;
        combsum(ans,a1,c,0,t);
        return ans;

    }
};