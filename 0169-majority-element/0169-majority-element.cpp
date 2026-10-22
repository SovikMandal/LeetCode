class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int currEle = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(count == 0) {
                currEle = nums[i];
            }

            if(nums[i] == currEle) count++;
            else count--;
        }

        return currEle;
    }
};