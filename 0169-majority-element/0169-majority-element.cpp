class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int currEle = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == currEle) count++;
            else {
                if(count == 0) {
                    currEle = nums[i];
                } else {
                    count--;
                }
            }
        }

        return currEle;
    }
};