class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;
        for(char ch : num) {
            int val = ch - '0';
            while(!st.empty() && st.top() > val && k > 0) {
                st.pop();
                k--;
            }

            st.push(val);
        }

        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        string ans = "";
        while (!st.empty()) {
            ans += char(st.top() + '0');
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        int i = 0;
        while (i < ans.size() && ans[i] == '0') {
            i++;
        }

        ans = ans.substr(i);
        return ans.empty() ? "0" : ans;
    }
};