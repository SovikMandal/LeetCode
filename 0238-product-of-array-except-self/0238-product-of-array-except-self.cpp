class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long product = 1;
        int zeroCount = 0;

        for (int x : nums) {
            if (x == 0) {
                zeroCount++;
            } else {
                product *= x;
            }
        }

        vector<int> res;

        for (int x : nums) {
            if (zeroCount >= 2) {
                res.push_back(0);
            } 
            else if (zeroCount == 1) {
                res.push_back(x == 0 ? product : 0);
            } 
            else {
                res.push_back(product / x);
            }
        }

        return res;
    }
};