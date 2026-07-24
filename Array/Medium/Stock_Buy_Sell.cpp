#include <iostream>
#include <vector>
#include <climits>
using namespace std;



// ---------------------------
// Optimal
// ---------------------------
int optimal(vector<int>& arr) {
int minm=arr[0];
int profit=0;
for(int i=1;i<arr.size();i++){
    profit=max(profit,arr[i]-minm);
    minm=min(arr[i],minm);
}
return profit;

}

int main() {

    vector<int> prices = {7, 6, 4, 3, 1};
    
    cout << "Optimal Answer : " << optimal(prices) << endl;

    return 0;
}