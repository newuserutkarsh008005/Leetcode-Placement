#include <iostream>
#include <vector>
using namespace std;

// ---------------------------
// Brute Force
// ---------------------------
vector<int> brute(vector<int>& arr) {

vector<int>pos;
vector<int>neg;
for(int i:arr){
    if(i>=0){
        pos.push_back(i);
    }
    else{
        neg.push_back(i);
    }
}
for(int i=0;i<(arr.size()/2);i++){

    arr[2*i]=pos[i];
    arr[2*i+1]=neg[i];
}

return arr;
}


// ---------------------------
// Optimal
// ---------------------------
vector<int> optimal(vector<int>& arr) {
    vector<int> ans(arr.size());
    int pos=0;
    int neg=1;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>=0){
            ans[pos]=arr[i];
            pos+=2;
        }
        else{
            ans[neg]=arr[i];
            neg+=2;
        }
    }
    return ans;



}

int main() {

    vector<int> arr = {3, 1, -2, -5, 2, -4};
    vector<int> arr1 = {3, 4, -9, -1, 10, -4};


    vector<int> ans1 = brute(arr);
   
    vector<int> ans3 = optimal(arr1);

    cout << "Brute Answer : ";
    for (int x : ans1) cout << x << " ";
    cout << endl;

   

    cout << "Optimal Answer : ";
    for (int x : ans3) cout << x << " ";
    cout << endl;

    return 0;
}