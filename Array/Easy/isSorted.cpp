#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

// --------------------------------------------------
// Brute Force
// --------------------------------------------------
bool brute(vector<int>& arr) {

   vector<int>a1=arr;
   sort(a1.begin(),a1.end());
   if(a1==arr)return true;
   return false;



}

// --------------------------------------------------
// Optimal
// --------------------------------------------------
bool optimal(vector<int>& arr) {

   for(int i=1;i<arr.size();i++){
    if(arr[i]<arr[i-1]){
        return false;
    }
   }
   return true;



}

int main() {

    // Test Cases

    // vector<int> arr = {1, 2, 3, 4, 5};      // true
    // vector<int> arr = {1, 2, 2, 3, 4};      // true
    // vector<int> arr = {5, 4, 3, 2, 1};      // false
    vector<int> arr = {1, 3, 2, 4, 5};         // false
    // vector<int> arr = {7};                  // true
    // vector<int> arr = {};                   // true

    cout << "Brute Answer  : " << brute(arr) << endl;
    cout << "Optimal Answer: " << optimal(arr) << endl;

    return 0;
}