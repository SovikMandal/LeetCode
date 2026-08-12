class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int i = 0;
        int maxFreq = 0;
        int res = 0;
        unordered_map<char, int> freq;
        for(int j = 0; j < n; j++) {
            freq[s[j]]++;
            maxFreq = max(maxFreq, freq[s[j]]);
            while((j - i + 1) - maxFreq > k) {
                freq[s[i]]--;
                i++;
            }

            res = max(res, j - i + 1);
        }

        return res;
    }
};