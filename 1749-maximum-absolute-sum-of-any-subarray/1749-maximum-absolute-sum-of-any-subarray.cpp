class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int currMaxSum = nums[0];
        int currMinSum = nums[0];
        int maxAbsSum = abs(nums[0]);

        for(int i = 1; i < n; i++) {
            currMaxSum = max(nums[i], currMaxSum + nums[i]);
            currMinSum = min(nums[i], currMinSum + nums[i]);
            maxAbsSum = max(maxAbsSum, max(abs(currMinSum), abs(currMaxSum)));
        }

        return maxAbsSum;
    }
};