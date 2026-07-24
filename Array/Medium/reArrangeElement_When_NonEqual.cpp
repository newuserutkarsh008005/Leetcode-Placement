#include <iostream>
#include <vector>
using namespace std;
// ---------------------------
// Optimal
// ---------------------------
vector<int> optimal(vector<int>& arr) {
  vector<int>pos,neg;
  for(int i:arr){
    if(i>=0){
        pos.push_back(i);
    }
    else{
        neg.push_back(i);
    }
  }
  //[1,2,3,4,-1,-2]==>[1,-1,2,-2,]
if(pos.size()>neg.size()){
    for(int i=0;i<neg.size();i++){
        arr[2*i]=pos[i];
        arr[2*i+1]=neg[i];
    }
    int ind=2*neg.size();
    for(int i=neg.size();i<pos.size();i++){
        arr[ind]=pos[i];
        ind++;
    }
}
else{
for(int i=0;i<pos.size();i++){
        arr[2*i]=pos[i];
        arr[2*i+1]=neg[i];
    }
    int ind=2*pos.size();
    for(int i=pos.size();i<neg.size();i++){
        arr[ind]=neg[i];
        ind++;
    }
}
return arr;

}

int main() {

    vector<int> arr = {3, 1, -2, -5, 2, -4};
    vector<int> arr1 = {3, 4, -9, -1, 10, -4,1,2,3,4};


    
   
    vector<int> ans3 = optimal(arr1);

    

   

    cout << "Optimal Answer : ";
    for (int x : ans3) cout << x << " ";
    cout << endl;

    return 0;
}