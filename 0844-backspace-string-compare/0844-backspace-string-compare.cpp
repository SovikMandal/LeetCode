class Solution {
public:
    string processed_string(string str) {
        string ans = "";
        for(int i = 0; i < str.length(); i++) {
            if(str[i] == '#') {
                if(ans.size() != 0) {
                    ans.pop_back();
                }
            }

            else ans += str[i];
        }

        return ans;
    }

    bool backspaceCompare(string s, string t) {
        string ps = processed_string(s);
        string pt = processed_string(t);

        if(ps == pt) return true;
        return false;
    }
};