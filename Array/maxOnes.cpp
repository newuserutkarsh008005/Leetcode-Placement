#include <iostream>
#include <vector>
using namespace std;



// --------------------------------------------------
// Optimal
// --------------------------------------------------
int optimal(vector<int>& arr) {

    int maxm=0;
    int c=0;
    for(int i:arr){
        if(i==1){
            c++;
            maxm=max(c,maxm);
        }
        else c=0;
    }
return maxm;
}

int main() {

    vector<int>arr = {0,1,1,1,1,0,1};  

   
    cout << "Optimal Answer : " << optimal(arr) << endl;

    return 0;
}