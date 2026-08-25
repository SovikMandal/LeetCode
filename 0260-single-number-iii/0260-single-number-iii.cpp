class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xor_all = 0;
        for(int i = 0; i < nums.size(); i++) {
            xor_all ^= nums[i];
        }

        long long mask = xor_all & -xor_all;
        int first_unique = 0;
        int second_unique = 0;

        for(int num : nums) {
            if(num & mask) {
                first_unique ^= num;
            } else {
                second_unique ^= num;
            }
        }

        return {first_unique, second_unique};
    }
};