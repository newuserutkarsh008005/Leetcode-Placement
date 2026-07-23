#include <iostream>
#include <vector>
#include<set>
using namespace std;

// --------------------------------------------------
// Brute Force
// --------------------------------------------------
int brute(vector<int>& arr) {

    set<int>st;
    for(int i:arr){
        st.insert(i);
    }
    int ind=0;
    for(auto it:st){
        arr[ind]=it;
        ind++;
    }
return ind;


}

// --------------------------------------------------
// Optimal
// --------------------------------------------------
int optimal(vector<int>& arr) {

    
    int j=0;
    for(int i=1;i<arr.size();i++){
        if(arr[i]!=arr[j]){
            arr[j+1]=arr[i];
            j++;
        }
    }
return j+1;


}

int main() {

    // Test Cases

    //vector<int> arr = {1, 1, 2};
     vector<int> arr = {0,0,1,1,1,2,2,3,3,4};
    // vector<int> arr = {1,2,3,4,5};
    // vector<int> arr = {1,1,1,1};
    // vector<int> arr = {5};
    // vector<int> arr = {};

    int k = brute(arr);
//int k = optimal(arr);

    cout << "Length : " << k << endl;
    cout << "Array  : ";

    for (int i = 0; i < k; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}