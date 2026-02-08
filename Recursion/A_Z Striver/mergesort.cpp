#include<iostream>
using namespace std;
void merge(vector<int>& nums,int l,int mid,int h){
vector<int>temp;
int low=l;
int high=mid+1;
while(low<=mid && high<=h){
    if(nums[low]<nums[high]){
        temp.push_back(nums[low]);
        low++;
    }
    else{
        temp.push_back(nums[high]);
        high++;

    }

}
while(low<=mid){
    temp.push_back(nums[low]);

    low++;

}
while(high<=h){
    temp.push_back(nums[high]);

    high++;
}
int j=0;
for(int i=0;i<temp.size();i++){
    cout<<temp[j]<<" ";
    j++;
    nums[i+l]=temp[i];
}
cout<<endl;
}
void msort(vector<int>& nums,int l,int h){
if(l>=h) return ;
    int mid =(l+h)/2;
    msort(nums,l,mid);
    msort(nums,mid+1,h);
    merge(nums,l,mid,h);

}
int main(){
vector<int>nums={10,20,30,40,11,9,2,0,91,12,33,92,109};
msort(nums,0,nums.size()-1);
for(int i=0;i<nums.size();i++){
    cout<<nums[i]<<" ";

}
cout<<endl;

    return 0;
}