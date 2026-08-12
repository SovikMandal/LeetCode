class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;
        int start = 0;
        vector<int> freq(128, -1);

        for(int end = 0; end < n; end++) {
            if(freq[s[end]] >= start) {
                start = freq[s[end]] + 1;
            }

            freq[s[end]] = end;
            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};