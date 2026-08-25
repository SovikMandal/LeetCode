class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> freq;
        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        for(auto num : freq) {
            if(num.second == 1) {
                ans.push_back(num.first);
            }
        }

        return ans;
    }
};