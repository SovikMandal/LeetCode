class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n;
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            n = nums[i];
            if((n >= 10 && n <= 99) || (n >= 1000 && n <= 9999) || (n == 100000)) {
                count++;
            }
        }

        return count;
    }
};