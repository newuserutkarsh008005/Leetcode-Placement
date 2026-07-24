#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// ---------------------------
// Brute Force
// ---------------------------
int brute(vector<int>& arr) {
    int n=arr.size();
    int mxsum=INT_MIN;
for(int i=0;i<n;i++){
    int sum=0;
    for(int j=i;j<n;j++){
        sum+=arr[j];
        mxsum=max(mxsum,sum);
    }
    


}
return mxsum;
}



// ---------------------------
// Optimal (Kadane's Algorithm)
// ---------------------------
int optimal(vector<int>& arr) {
    int sum=0;
    int maxm=INT_MIN;
    int start=0;
    int end=0,astart=0;
    
   for(int i=0;i<arr.size();i++){
    if(sum==0){
        start=i;
    }
    sum+=arr[i];
   if(sum>maxm){
    maxm=sum;
 astart=start;
    end=i;
   }
   
    
    if(sum<0){
        sum=0;
    }

   }
   cout<<"SUbarray Printing";
for(int i=astart;i<=end;i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
return maxm;
}

int main() {

    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << "Brute Answer : " << brute(arr) << endl;
    cout << "Optimal Answer : " << optimal(arr) << endl;

    return 0;
}