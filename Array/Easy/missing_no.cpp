#include <iostream>
#include <vector>
using namespace std;

// --------------------------------------------------
// Brute Force
// --------------------------------------------------
int brute(vector<int>& arr, int N) {

    for(int i=1;i<=N;i++){
        int flag=0;
        int tar=i;
        for(int j=0;j<arr.size();j++){
            if(tar==arr[j]){
                flag=1;
                break;
            }
        }
        if(flag==0)return i;
    }
return -1;

}

// --------------------------------------------------
// Better
// --------------------------------------------------
int better(vector<int>& arr, int N) {

  vector<int>ans(arr.size()+1,0);
  for(int i=0;i<arr.size();i++){
    ans[arr[i]]=1;
  }
  for(int i= 1;i<ans.size();i++){
    if(ans[i]!=1)return i;
  }
return -1;
}

// --------------------------------------------------
// Optimal ver-1
// --------------------------------------------------
int optimal1(vector<int>& arr, int N) {
int sum=(N*(N+1))/2;
int sum2=0;
for(int i:arr){
    sum2+=i;
}
return sum-sum2==0?-1:sum-sum2;
   

}
// --------------------------------------------------
// Optimal ver-2
// --------------------------------------------------
int optimal2(vector<int>& arr, int N) {
int x1=0;
int x2=0;
for(int i=0;i<arr.size();i++){
    x1=x1^arr[i];
    x2=x2^(i+1);
}
x2=x2^N;
int ans=x1^x2;
return ans==0?-1:ans;

}

int main() {

    vector<int> arr = {1, 2, 4, 5};

    int N = 5;

    cout << "Brute Answer : " << brute(arr, N) << endl;
    cout << "Better Answer : " << better(arr, N) << endl;
    cout << "Optimal Answer : " << optimal1(arr, N) << endl;
    cout << "Optimal2 Answer : " << optimal2(arr, N) << endl;

    return 0;
}