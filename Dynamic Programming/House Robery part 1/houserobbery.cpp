#include<iostream>
using namespace std;
int houserobbery(vector<int>&houses,int n,vector<int>&dp){
   int p2=0;
   int p1=houses[0];
   for(int i=1;i<n;i++){
    int keep=houses[i];
    if(i-2>=0)keep+=p2;
    int notkeep=p1;
    int curr=max(keep,notkeep);
    p2=p1;
    p1=curr;
   }
   return p1;
}
int main(){
vector<int>houses;
int n;
cin>>n;
int j;
vector<int>dp(n);
for(int i=0;i<n;i++){
    cin>>j;
    houses.push_back(j);
}
int maxmprofit=houserobbery(houses,n,dp);
cout<<maxmprofit<<endl;
    return 0;
}




















