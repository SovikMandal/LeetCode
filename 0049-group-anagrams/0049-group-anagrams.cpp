class Solution {
private:
    string generate(string str) {
        int arr[26] = {0};
        for(char ch : str) {
            arr[ch - 'a']++;
        }

        string newString = "";
        for(int i = 0; i < 26; i++) {
            int freq = arr[i];
            if(freq > 0) newString += string(freq, i + 'a');
        }

        return newString;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        for(string s : strs) {
            mp[generate(s)].push_back(s);
        }

        for(auto [key, val] : mp) {
            res.push_back(val);
        }

        return res;
    }
};