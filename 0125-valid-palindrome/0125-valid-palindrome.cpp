class Solution {
public:
    bool vaildPalindrome(string s) {
        int n = s.length();
        int left = 0;
        int right = n -1;
        while(left < right) {
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }

        return true;
    }

    bool isPalindrome(string s) {
        if(s.empty()) return true;
        string newString = "";
        for(int i = 0; i < s.length(); i++) {
            if(s[i] >= 'A' && s[i] <= 'Z') newString.push_back(tolower(s[i]));
            else if(s[i] >= 'a' && s[i] <= 'z') newString.push_back(s[i]);
            else if(s[i] >= '0' && s[i] <= '9') newString.push_back(s[i]);
        }

        if(vaildPalindrome(newString)) return true;
        return false;
    }
};