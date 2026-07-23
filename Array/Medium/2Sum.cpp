#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// --------------------------------------------------
// Brute Force
// --------------------------------------------------
vector<int> brute(vector<int>& arr, int target) {
vector<int>ans;
int n=arr.size();
for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        if(arr[i]+arr[j]==target){
            ans.push_back(i);
                ans.push_back(j);
                break;
        }
    }
}
  return ans;  
    
}

// --------------------------------------------------
// Better
// --------------------------------------------------
vector<int> better(vector<int>& arr, int target) {

   unordered_map<int,int>mp;
   for(int i=0;i<arr.size();i++){
    int t=target-arr[i];
    if(mp.find(t)!=mp.end()){
        return {i,mp[t]};
    }
    mp[arr[i]]=i;
   }
    return {-1, -1};
}

// --------------------------------------------------
// Optimal (Only for Sorted Array)
// --------------------------------------------------
vector<int> optimal(vector<int>& arr, int target) {

    sort(arr.begin(),arr.end());
    int left=0,right=arr.size()-1;
    while(left<right){
        if(arr[left]+arr[right]==target){
            return {left,right};
        }
        else if (arr[left]+arr[right]>target){
            right--;
        }
        else{
            left++;
        }
    }

    return {-1, -1};
}

int main() {

    vector<int> arr = {2, 7, 11, 15};
    int target = 9;

    vector<int> ans1 = brute(arr, target);
    vector<int> ans2 = better(arr, target);
    vector<int> ans3 = optimal(arr, target);

    cout << "Brute Answer : " << ans1[0] << " " << ans1[1] << endl;
    cout << "Better Answer : " << ans2[0] << " " << ans2[1] << endl;
    cout << "Optimal Answer : " << ans3[0] << " " << ans3[1] << endl;

    return 0;
}