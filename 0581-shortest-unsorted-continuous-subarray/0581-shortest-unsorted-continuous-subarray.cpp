class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = -1;
        int right = -1;
        int minSeen = nums[n - 1];
        int maxSeen = nums[0];

        for(int i = 1; i < n; i++) {
            maxSeen = max(maxSeen, nums[i]);
            if(maxSeen > nums[i]) {
                right = i;
            }
        }

        for(int i = n - 2; i >= 0; i--) {
            minSeen = min(minSeen, nums[i]);
            if(minSeen < nums[i]) {
                left = i;
            }
        }

        if(right == -1) return 0;
        return (right - left + 1);
    }
};