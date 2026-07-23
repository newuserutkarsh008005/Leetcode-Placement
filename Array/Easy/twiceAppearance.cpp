#include <iostream>
#include <vector>
using namespace std;

// --------------------------------------------------
// Brute Force
// --------------------------------------------------
int brute(vector<int>& arr) {

    for(int i=0;i<arr.size();i++){
        int c=0;
        for(int j=0;j<arr.size();j++){
            if(arr[i]==arr[j]){
                c++;
            }
        }
        if(c==1)return arr[i];
    }
return -1;
}

// --------------------------------------------------
// Better
// --------------------------------------------------
int better(vector<int>& arr) {

    int maxm=-1e9;
    for(int i:arr){
        maxm=max(i,maxm);

    }
    vector<int>ans(maxm+1,0);
    for(int i=0;i<arr.size();i++){
        ans[arr[i]]++;
    }
    for(int j=1;j<ans.size();j++){
        if(ans[j]==1)return j;
    }
    return -1;
}
// --------------------------------------------------
// Better ->2
// --------------------------------------------------
int better2(vector<int>& arr) {
unordered_map<int, int> mp;

for (int x : arr)
    mp[x]++;

for (int x : arr)
    if (mp[x] == 1)
        return x;
}

// --------------------------------------------------
// Optimal
// --------------------------------------------------
int optimal(vector<int>& arr) {

  int x=0;
  for(int i:arr){
    x=x^i;
  }

return x;
}

int main() {

    vector<int> arr = {4,1,2,1,2};

    cout << "Brute Answer : " << brute(arr) << endl;
    cout << "Better Answer : " << better(arr) << endl;
    cout << "Better 2 Answer : " << better2(arr) << endl;
    cout << "Optimal Answer : " << optimal(arr) << endl;

    return 0;
}