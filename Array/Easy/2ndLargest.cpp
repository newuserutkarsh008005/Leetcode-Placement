#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

// --------------------------------------------------
// Brute Force
// --------------------------------------------------
int brute(vector<int>& arr) {
sort(arr.begin(), arr.end());

int largest = arr.back();

for (int i = arr.size() - 2; i >= 0; i--) {
    if (arr[i] != largest)
        return arr[i];
}

return -1;

}



// --------------------------------------------------
// Better
// --------------------------------------------------
int better(vector<int>& arr) {

   int l=arr[0];
   int sec=-1;
   int n=arr.size();
   for(int i =0;i<n;i++){
    l=max(l,arr[i]);
   }
   for(int i=0;i<n;i++){
    if(arr[i]>sec && arr[i]!=l){
        sec=arr[i];
    }
   }
   return sec;


}

// --------------------------------------------------
// Optimal
// --------------------------------------------------
int optimal(vector<int>& arr) {

   int l=arr[0];
   int sec=-1;
   for(int i :arr){
    if(i>l){
        
        sec=l;
        l=i;
    }
    else if(l>i){
        if(sec<i){
            sec=i;
        }
    }
   }
   return sec;

}

int main() {

    // Test Case
//     vector<int> arr = {12, 35, 1, 10, 34, 1};
//     vector<int> arr = {12, 35, 1, 10, 34, 1};       // 34
// vector<int> arr = {10, 5, 10};                  // 5
//vector<int> arr = {5, 5, 5, 5};                 // -1 (or as per problem)
// vector<int> arr = {1, 2};                       // 1
// vector<int> arr = {2, 1};                       // 1
// vector<int> arr = {7};                          // -1
vector<int> arr = {-1, -2, -3, -4};             // -2
// vector<int> arr = {100, 90, 80, 70, 60};        // 90

    // Uncomment the approach you want to test

     cout << "Brute Answer  : " << brute(arr) << endl;
     cout << "Better Answer : " << better(arr) << endl;
    cout << "Optimal Answer: " << optimal(arr) << endl;

    return 0;
}