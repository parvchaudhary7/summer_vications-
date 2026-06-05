#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> sortedSquares(vector<int>& nums) {

    int left = 0;
    int right = nums.size() - 1;

    vector<int> result(nums.size());

    int pos = nums.size() - 1;

    while(left <= right) {

        if(abs(nums[left]) > abs(nums[right])) {
            result[pos] = nums[left] * nums[left];
            left++;
        }
        else {
            result[pos] = nums[right] * nums[right];
            right--;
        }

        pos--;
    }

    return result;
}

int main() {

    vector<int> nums = {-4,-1,0,3,10};

    vector<int> ans = sortedSquares(nums);

    for(int x : ans)
        cout << x << " ";

    return 0;
}