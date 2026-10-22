class Solution {
private:
    string generate(string str) {
        sort(str.begin(), str.end());
        return str;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        for(string s : strs) {
            string value = s;
            string key = generate(value);
            mp[key].push_back(value);
        }

        for(auto [key, val] : mp) {
            res.push_back(val);
        }

        return res;
    }
};