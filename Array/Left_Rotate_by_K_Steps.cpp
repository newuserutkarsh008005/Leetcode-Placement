#include <iostream>
#include <vector>
using namespace std;

// --------------------------------------------------
// Brute Force --(0(n+d))
// Space =o(n)
// --------------------------------------------------
void brute(vector<int>& arr, int d) {
int n=arr.size();
d=d%n;
vector<int>temp;
for(int i=0;i<d;i++){
    temp.push_back(arr[i]);
}
for(int i=d;i<n;i++){
    arr[i-d]=arr[i];
}
for(int i=n-d;i<n;i++){
    arr[i]=temp[i-(n-d)];
}

}

// --------------------------------------------------
// Optimal--- Time =O(2n)
// Space ---O(1)
// --------------------------------------------------
void optimal(vector<int>& arr, int d) {

    int n=arr.size();
     d=d%n;
    reverse(arr.begin(),arr.begin()+d);
    reverse(arr.begin()+d,arr.end());
    reverse(arr.begin(),arr.end());



}

int main() {

    // Test Cases

    vector<int> arr = {1, 2, 3, 4, 5};
    // vector<int> arr = {7};
    // vector<int> arr = {10, 20};
    // vector<int> arr = {4, 8, 6, 2, 1};

    int d = 2;

    // brute(arr, d);
    optimal(arr, d);

    cout << "Rotated Array: ";

    for (int x : arr) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}