class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> nonZeros;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                nonZeros.push_back(nums[i]);
            }
        }

        for(int i = 0; i < nonZeros.size(); i++) {
            nums[i] = nonZeros[i];
        }

        for(int i = nonZeros.size(); i < n; i++) {
            nums[i] = 0;
        }
    }
};