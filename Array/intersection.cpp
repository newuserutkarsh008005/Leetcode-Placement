#include <iostream>
#include <vector>
using namespace std;

// --------------------------------------------------
// Brute Force
// --------------------------------------------------
vector<int> brute(vector<int>& arr1, vector<int>& arr2) {
vector<int>visited(arr2.size(),0);
vector<int>ans;
for(int i=0;i<arr1.size();i++){
    for(int j=0;j<arr2.size();j++){
        if(arr1[i]==arr2[j] && visited[j]==0){
            ans.push_back(arr1[i]);
            visited[j]=1;
            break;
        }
        if(arr1[i]<arr2[j]){
            break;
        }
    }
}
   return ans;

}

// --------------------------------------------------
// Optimal
// --------------------------------------------------
vector<int> optimal(vector<int>& arr1, vector<int>& arr2) {

    // Write optimal logic here
int i=0;
int j=0;
int n1=arr1.size();
int n2=arr2.size();
vector<int>ans;
while(i<n1 && j<n2){
    if(arr1[i]>arr2[j]){
j++;
    }
    else if(arr1[i]<arr2[j]){
        i++;
    }
    else {
        ans.push_back(arr1[i]);
        i++;
        j++;
    }
}
return ans;
}

int main() {

    vector<int> arr1 = {1,2,3,4,5,6,7,8};
    vector<int> arr2 = {1,1,2,2,3,4,5,6,6,8,9,10};

    vector<int> bruteAns = brute(arr1, arr2);
    vector<int> optimalAns = optimal(arr1, arr2);

    cout << "Brute Answer : ";
    for (int x : bruteAns)
        cout << x << " ";
    cout << endl;

    cout << "Optimal Answer : ";
    for (int x : optimalAns)
        cout << x << " ";
    cout << endl;

    return 0;
}