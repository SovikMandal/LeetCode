class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> prefix;
        int maxVal = 0;
        for(int i = 0; i < nums.size(); i++) {
            maxVal = max(maxVal, nums[i]);
            prefix.push_back(maxVal);
        }

        vector<int> prefixGcd;
        for(int i = 0; i < prefix.size(); i++) {
            int val = gcd(nums[i], prefix[i]);
            prefixGcd.push_back(val);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        int left = 0;
        int right = prefixGcd.size() - 1;
        long long sum = 0;

        while(left < right) {
            int val = gcd(prefixGcd[left], prefixGcd[right]);
            sum = sum + val;
            left++;
            right--;
        }

        return sum;
    }
};