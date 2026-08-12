class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int minLength = INT_MAX;
        int sum = 0;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            while(sum >= target) {
                minLength = min(minLength, i - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        return minLength == INT_MAX ? 0 : minLength;
    }
};