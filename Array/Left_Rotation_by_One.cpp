#include <iostream>
#include <vector>
using namespace std;

// --------------------------------------------------
// Brute Force
// --------------------------------------------------
void brute(vector<int>& arr) {

   arr.push_back(arr[0]);
   arr.erase(arr.begin());



}

// --------------------------------------------------
// Optimal
// --------------------------------------------------
void optimal(vector<int>& arr) {
int temp=arr[0];
    for(int i=1;i<arr.size();i++){
        arr[i-1]=arr[i];
    }
    arr[arr.size()-1]=temp;


}

int main() {

    // Test Cases

    vector<int> arr = {1, 2, 3, 4, 5};
    // vector<int> arr = {7};
    // vector<int> arr = {10, 20};
    // vector<int> arr = {4, 8, 6, 2, 1};

     //brute(arr);
    optimal(arr);

    cout << "Rotated Array: ";

    for (int x : arr) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}