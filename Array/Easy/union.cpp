#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// --------------------------------------------------
// Brute Force
// --------------------------------------------------
vector<int> brute(vector<int>& arr1, vector<int>& arr2) {
    set<int>st;
    for(int i:arr1){
        st.insert(i);
    }
for(int i:arr2){
        st.insert(i);
}

vector<int>ans;
for(auto &it:st){
    ans.push_back(it);
}
return ans;
}

// --------------------------------------------------
// Optimal
// --------------------------------------------------
vector<int> optimal(vector<int>& arr1, vector<int>& arr2) {
vector<int>ans;
int n1=arr1.size();
int n2=arr2.size();
int i=0;
int j=0;
while(i<n1 && j<n2){
    if(arr1[i]<=arr2[j]){
        if(ans.empty()|| ans.back()!=arr1[i]){
        ans.push_back(arr1[i]);
    }
    i++;
}
else{
     if(ans.empty()|| ans.back()!=arr2[j]){
        ans.push_back(arr2[j]);
    }
    j++;
}
}
while(i<n1){
 
        if(ans.empty()|| ans.back()!=arr1[i]){
        ans.push_back(arr1[i]);
    }
    i++;
}
while(j<n2){
 
        if(ans.empty()|| ans.back()!=arr2[j]){
        ans.push_back(arr2[j]);
    }
    j++;
}
return ans;

}

int main() {

    //Test Cases

    vector<int> arr1 = {1,2,3,4,6,7,8};
    vector<int> arr2 = {1,2,3,4,5,6,7,9,10};

    vector<int> ans1 = brute(arr1, arr2);

    cout << "Brute Answer  : ";
    for (int x : ans1) cout << x << " ";
    cout << endl;

    vector<int> ans2 = optimal(arr1, arr2);

    cout << "Optimal Answer: ";
    for (int x : ans2) cout << x << " ";
    cout << endl;

    return 0;
}