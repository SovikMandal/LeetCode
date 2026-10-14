class Solution {
private:
    string generate(string& str) {
        int arr[26] = {0};
        for(char ch : str) {
            arr[ch - 'a']++;
        }

        string newString = "";
        for(int i = 0; i < 26; i++) {
            int freq = arr[i]; 
            if(freq > 0) {
                newString += string(freq, i + 'a');
            }
        }

        return newString;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> result;
        unordered_map<string, vector<string>> mp;
        for(string s : strs) {
            string word = s;
            string key = generate(word);
            mp[key].push_back(word);
        }

        for(auto [key, value] : mp) {
            result.push_back(value);
        }

        return result;
    }
};