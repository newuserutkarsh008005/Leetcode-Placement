#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

// --------------------------------------------------
// Brute Force
// --------------------------------------------------
int brute(vector<int>& arr) {

   sort(arr.begin(),arr.end());
   return arr[arr.size()-1];



}

// --------------------------------------------------
// Optimal
// --------------------------------------------------
int optimal(vector<int>& arr) {

   int maxm=arr[0];
   for(int i:arr){
    
   maxm=max(i,maxm);



}
return maxm;}

int main() {

    vector<int> arr = {7, 2, 15, 8, 10, 1, 25, 6};

   

     cout << "Brute Answer : " << brute(arr) << endl;
    cout << "Optimal Answer : " << optimal(arr) << endl;

    return 0;
}