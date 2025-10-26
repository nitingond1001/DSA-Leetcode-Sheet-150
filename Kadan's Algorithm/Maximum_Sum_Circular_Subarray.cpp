class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        int curMax = 0, maxSum = INT_MIN;
        int curMin = 0, minSum = INT_MAX;

        for(int num : nums){
            curMax = max(num, curMax + num);
            maxSum = max(maxSum, curMax);

            curMin = min(num, curMin + num);
            minSum = min(minSum, curMin);

            totalSum += num;
        }
        if(maxSum < 0) return maxSum;
        return max(maxSum, totalSum - minSum);
    }
};
