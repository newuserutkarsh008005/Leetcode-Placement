#include<iostream>
using namespace std;
int houserobbery(vector<int>&houses,int n,vector<int>&dp){
    if(n<0)return 0;
    if(n==0)return houses[n];

    if(dp[n]!=-1)return dp[n];
    int keep=houses[n]+houserobbery(houses,n-2,dp);
    int notkeep=0+houserobbery(houses,n-1,dp);
    return dp[n]=max(keep,notkeep);
}
int main(){
vector<int>houses;
int n;
cin>>n;
int j;
vector<int>dp(n,-1);
for(int i=0;i<n;i++){
    cin>>j;
    houses.push_back(j);
}
int maxmprofit=houserobbery(houses,n-1,dp);
cout<<maxmprofit<<endl;
    return 0;
}




















