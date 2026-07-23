#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// --------------------------------------------------
// Brute Force
// --------------------------------------------------
int brute(vector<int>& arr, int k) {
    int n=arr.size();
   int ans=0;
   for(int i=0;i<n;i++){
    int sum=0;
    for(int j=i;j<n;j++){
        sum+=arr[j];
        if(sum==k)ans=max(ans,j-i+1);

    }
   }

    return ans;
}

// --------------------------------------------------
// Better
// --------------------------------------------------


// --------------------------------------------------
// Better -> 2 (Only for Positive Numbers)
// --------------------------------------------------
int better2(vector<int>& arr, int k) {
    int left=0;
    int right=0;
    int n=arr.size();
    int ans=0;
    int sum=0;
    while(right<n){
        //collecting the current sum

         sum+=arr[right];

        //left trim if exceeds k

        while(left<n && sum>k){
            sum-=arr[left];
            left++;
        }

        //sum equals k

        if(sum==k)ans=max(ans,right-left+1);

        //window forwarding 
       
        right++;
    }
    

    return ans;
}

// --------------------------------------------------
// Optimal
// --------------------------------------------------
int optimal(vector<int>& arr, int k) {

   unordered_map<int,int>mp;
   int ans=0;
   int psum=0;
   for(int i=0;i<arr.size();i++){
       psum+=arr[i];
    if(psum==k)ans=max(ans,i+1);
    int tar=psum-k;
    if(mp.find(tar)!=mp.end()){
        ans=max(ans,i-mp[tar]);
    }
    if(mp.find(psum)==mp.end()) mp[psum]=i;
   
   }

    return ans;
}

int main() {

    vector<int> arr = {1, 2, 1, 1, 1};
    int k = 3;

    cout << "Brute Answer : " << brute(arr, k) << endl;
    
    cout << "Better 2 Answer : " << better2(arr, k) << endl;
    cout << "Optimal Answer : " << optimal(arr, k) << endl;

    return 0;
}