class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int firstHigest = 0;
        int secondHigest = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > firstHigest) {
                secondHigest = firstHigest;
                firstHigest = nums[i];
            } else {
               secondHigest = max(secondHigest, nums[i]); 
            }
        }

        int ans = (firstHigest - 1) * (secondHigest - 1);
        return ans;
    }
};