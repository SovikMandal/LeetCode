class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0;
        int fast = 1;
        int n = nums.size();
        while(n > fast) {
            if(nums[slow] != nums[fast]) {
                slow += 1;
                nums[slow] = nums[fast];
            }

            else {
                fast++;
            }
        }

        return slow + 1;
    }
};