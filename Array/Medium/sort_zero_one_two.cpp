#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

// ---------------------------
// Brute Force
// ---------------------------
void brute(vector<int>& arr) {
sort(arr.begin(),arr.end());


}

// ---------------------------
// Better
// ---------------------------
void better(vector<int>& arr) {
int zero=0,one=0,two=0;
for(int i:arr){
    if(i==0)zero++;
    else if(i==1)one++;
    else two++;
}
for(int i=0;i<zero;i++){
    arr[i]=0;
}
for(int i=zero;i<zero+one;i++){
    arr[i]=1;
}
for(int i=zero+one;i<arr.size();i++){
    arr[i]=2;
}


}

// ---------------------------
// Optimal (Dutch National Flag)
// ---------------------------
void optimal(vector<int>& arr) {

//three operation 
/*
1) [0 to low -1 | low to mid-1 | mid to high-1| high to end]
    0's Sorted.   1's Sorted.     Unsorted.      2's Sorted 

    rule -> assume whole arr is unsorted i.e range from mid to high -1 {low=0,mid=0,high=n-1}
    mid-> 0{ swap (low,mid) and (low++ and mid++)}
    mid-> 1 {mid++}
    mid-> 2 {swap (mid,high), and high --}
*/

int low=0,mid=0;
int high=arr.size()-1;
while(mid<=high){
    if(arr[mid]==0){
        swap(arr[mid],arr[low]);
        low++,mid++;

    }
    else if(arr[mid]==1){
mid++;

    }
    else{
swap(arr[mid],arr[high]);
high--;
    }
}


}

int main() {

    vector<int> arr = {2, 0, 2, 1, 1, 0};

    optimal(arr);
    // better(arr);
    // optimal(arr);

    for (int x : arr)
        cout << x << " ";

    return 0;
}