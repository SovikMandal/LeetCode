class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0;
        int n = nums.size();
        for(int i = 1; i < n; i++) {
            if(nums[i] != nums[slow]) {
                slow++;
                nums[slow] = nums[i];
            }
        }

        return slow + 1;
    }
};