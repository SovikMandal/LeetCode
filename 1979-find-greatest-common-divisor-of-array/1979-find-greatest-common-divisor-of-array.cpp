class Solution {
public:
    int findGCD(vector<int>& nums) {
        int largestNum = INT_MIN;
        int smallestNum = INT_MAX;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > largestNum) {
                largestNum = nums[i];
            }

            if(nums[i] < smallestNum) {
                smallestNum = nums[i];
            }
        }

        int res = gcd(smallestNum, largestNum);
        return res;
    }
};