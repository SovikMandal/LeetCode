class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        int start = 0;
        int maxLength = 0;
        unordered_map<char,int> freq;

        for(int end = 0; end < n; end++) {
            freq[s[end]]++;
            while(freq[s[end]] > 2) {
                freq[s[start]]--;
                start++;
            }

            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength++;
    }
};