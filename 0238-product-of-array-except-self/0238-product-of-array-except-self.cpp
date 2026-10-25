class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zerosCount = 0;
        int product = 1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) zerosCount++;
            else product *= nums[i];
        }

        vector<int> ans(nums.size(), 0);
        if(zerosCount > 1) {
            return ans;
        } else {
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] == 0) ans[i] = product;
                else ans[i] = 0;
            }
        }

        if(zerosCount == 0) {
            for(int i = 0; i < nums.size(); i++) {
                ans[i] = product/nums[i];
            }
        }

        return ans;
    }
};