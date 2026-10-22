class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int x : nums) {
            freq[x]++;
        }

        for(auto [key, val] : freq) {
            if(val > nums.size()/2) return key;
        }

        return -1;
    }
};