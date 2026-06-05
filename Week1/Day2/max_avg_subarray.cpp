#include <iostream>
#include <vector>

using namespace std;

double findMaxAverage(vector<int>& nums, int k) {

    double sum = 0;

    for(int i = 0; i < k; i++)
        sum += nums[i];

    double maxSum = sum;

    for(int i = k; i < nums.size(); i++) {

        sum += nums[i];
        sum -= nums[i-k];

        maxSum = max(maxSum, sum);
    }

    return maxSum / k;
}

int main() {

    vector<int> nums = {1,12,-5,-6,50,3};
    int k = 4;

    cout << findMaxAverage(nums, k);

    return 0;
}