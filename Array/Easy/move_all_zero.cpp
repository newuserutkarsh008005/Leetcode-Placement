#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// --------------------------------------------------
// Brute Force
// --------------------------------------------------
vector<int> brute(vector<int>& arr) {

vector<int>temp;
for(int i:arr){
    if(i!=0){
        temp.push_back(i);
    }
}
for(int i=0;i<temp.size();i++){
    arr[i]=temp[i];
}
if(temp.size()<arr.size()){
    for(int i=temp.size();i<arr.size();i++){
        arr[i]=0;
    }
}
return arr;


}

// --------------------------------------------------
// Optimal
// --------------------------------------------------
vector<int> optimal(vector<int>& arr) {
    int j=-1;
for(int i=0;i<arr.size();i++){
    if(arr[i]==0){j=i;
    break;
    }
}
for(int i=j+1;i<arr.size();i++){
if(arr[i]!=0){
    swap(arr[i],arr[j]);
    j++;
}
}

return arr;

}

int main() {

    // Test Cases

    // vector<int> arr = {};
    // vector<int> arr = {};
    // vector<int> arr = {};
    vector<int> arr = {1,0,1,0,1,0,1,0};
    // vector<int> arr = {};
    // vector<int> arr = {};

    vector<int> ans1 = brute(arr);

    cout << "Brute Answer  : ";
    for (int x : ans1) cout << x << " ";
    cout << endl;

    // Reinitialize array for optimal approach
    arr = {1,0,1,0,1,0,1,0};

    vector<int> ans2 = optimal(arr);

    cout << "Optimal Answer: ";
    for (int x : ans2) cout << x << " ";
    cout << endl;

    return 0;
}