#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// ---------------------------
// Brute Force
// ---------------------------
int brute(vector<int>& arr) {
int n=arr.size();
    for(int i=0;i<n;i++){
int element=arr[i];
int count=0;
for(int j=0;j<n;j++){
    if( arr[j]==element){
        count++;
    }
}
if(count>(n/2))return element;
    }
return -1;
}

// ---------------------------
// Better (Hash Map)
// ---------------------------
int better(vector<int>& arr) {
    unordered_map<int,int>freq;
    for(int i:arr){
        freq[i]++;
    }
    int target=arr.size()/2;
    for(auto &it:freq){
        if(it.second>target)return it.first;
    }
return -1;
}

// ---------------------------
// Optimal (Moore's Voting Algorithm)
// ---------------------------
int optimal(vector<int>& arr) {
    int elem=-1e9;
    int count=0;
    for(int i=0;i<arr.size();i++){
        if(count==0){
            elem=arr[i];
            count++;
        }
        else if(arr[i]==elem){
            count++;
        }
        else count--;
    }
    if(elem!=-1e9){
        int freq=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==elem){
                freq++;
            }
        }
        if(freq>(arr.size()/2))return elem;
    }

return -1;
}

int main() {

    vector<int> arr = {3, 2, 3};

    cout << "Brute Answer : " << brute(arr) << endl;
    cout << "Better Answer : " << better(arr) << endl;
    cout << "Optimal Answer : " << optimal(arr) << endl;

    return 0;
}