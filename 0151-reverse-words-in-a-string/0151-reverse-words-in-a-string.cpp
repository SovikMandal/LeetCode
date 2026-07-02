class Solution {
public:
    string reverseWords(string s) {
        string str = "";
        stack<string> st;
        for(char ch : s) {
            if(ch == ' ') {
                if(!str.empty()) {
                    st.push(str);
                    str = "";
                }
            } else {
                str += ch;
            }
        }

        if(!str.empty()) st.push(str);
        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
            if(!st.empty()) ans += ' ';
        }
        
        return ans;
    }
};