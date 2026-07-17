class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<long long> freq(mx + 1, 0);
        for (int x : nums) {
            freq[x]++;
        }

        vector<long long> cntDiv(mx + 1, 0);
        for (int g = 1; g <= mx; g++) {
            for (int multiple = g; multiple <= mx; multiple += g) {
                cntDiv[g] += freq[multiple];
            }
        }

        vector<long long> exact(mx + 1, 0);

        for (int g = mx; g >= 1; g--) {
            long long pairs = cntDiv[g] * (cntDiv[g] - 1) / 2;

            for (int multiple = 2 * g; multiple <= mx; multiple += g) {
                pairs -= exact[multiple];
            }

            exact[g] = pairs;
        }

        vector<long long> prefix;
        vector<int> value;

        long long sum = 0;
        for (int g = 1; g <= mx; g++) {
            if (exact[g] > 0) {
                sum += exact[g];
                prefix.push_back(sum);
                value.push_back(g);
            }
        }

        vector<int> ans;

        for (long long q : queries) {
            int idx = lower_bound(prefix.begin(), prefix.end(), q + 1) - prefix.begin();
            ans.push_back(value[idx]);
        }

        return ans;
    }
};