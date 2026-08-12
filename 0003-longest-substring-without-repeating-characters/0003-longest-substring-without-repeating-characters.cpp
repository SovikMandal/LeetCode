class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;
        int start = 0;
        unordered_map<char, int> freq;

        for(int end = 0; end < n; end++) {
            freq[s[end]]++;
            while(freq[s[end]] > 1) {
                freq[s[start]]--;
                start++;
            }

            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};