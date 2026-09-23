#include <iostream>
#include <vector>

using namespace std;

void insertSubarray(vector<int>& arr, const vector<int>& sub, int index) {
    arr.insert(arr.begin() + index, sub.begin(), sub.end());
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> sub = {9, 9};
    int pos = 2;

    insertSubarray(nums, sub, pos);

    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}