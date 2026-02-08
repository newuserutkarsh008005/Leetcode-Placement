#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& nums, int st, int en) {
    int pivot = nums[en];
    int i = st - 1;

    for (int j = st; j < en; j++) {
        if (nums[j] <= pivot) {
            i++;
            swap(nums[i], nums[j]);
        }
    }

    swap(nums[i + 1], nums[en]);
    return i + 1;
}

void quicksort(vector<int>& nums, int st, int en) {
    if (st >= en) return;

    int p = partition(nums, st, en);
    quicksort(nums, st, p - 1);
    quicksort(nums, p + 1, en);
}

int main() {
    vector<int> nums = {1,2,3,10,4,5,6,9,100,90,0};
    quicksort(nums, 0, nums.size() - 1);

    for (int x : nums) cout << x << " ";
    return 0;
}
