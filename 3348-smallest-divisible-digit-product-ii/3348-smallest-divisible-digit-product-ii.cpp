class Solution {
public:
    string smallestNumber(string num, long long t) {
        int req2 = 0, req3 = 0, req5 = 0, req7 = 0;
        long long temp = t;
        while (temp % 2 == 0) { req2++; temp /= 2; }
        while (temp % 3 == 0) { req3++; temp /= 3; }
        while (temp % 5 == 0) { req5++; temp /= 5; }
        while (temp % 7 == 0) { req7++; temp /= 7; }
        
        if (temp > 1) return "-1";
        
        int MAX2 = req2 + 1;
        int MAX3 = req3 + 1;
        vector<vector<int>> dp(MAX2, vector<int>(MAX3, 1e9));
        dp[0][0] = 0;
        
        for (int i = 0; i < MAX2; ++i) {
            for (int j = 0; j < MAX3; ++j) {
                if (i == 0 && j == 0) continue;
                int res = 1e9;
                res = min(res, 1 + dp[max(0, i - 1)][max(0, j - 0)]);
                res = min(res, 1 + dp[max(0, i - 0)][max(0, j - 1)]);
                res = min(res, 1 + dp[max(0, i - 2)][max(0, j - 0)]);
                res = min(res, 1 + dp[max(0, i - 1)][max(0, j - 1)]);
                res = min(res, 1 + dp[max(0, i - 3)][max(0, j - 0)]);
                res = min(res, 1 + dp[max(0, i - 0)][max(0, j - 2)]);
                dp[i][j] = res;
            }
        }
        
        auto get_dp = [&](int r2, int r3) {
            return dp[min(r2, req2)][min(r3, req3)];
        };
        
        int L = num.length();
        vector<int> p2(L + 1, req2), p3(L + 1, req3), p5(L + 1, req5), p7(L + 1, req7);
        int z_idx = L;
        
        int c2_arr[10] = {0, 0, 1, 0, 2, 0, 1, 0, 3, 0};
        int c3_arr[10] = {0, 0, 0, 1, 0, 0, 1, 0, 0, 2};
        int c5_arr[10] = {0, 0, 0, 0, 0, 1, 0, 0, 0, 0};
        int c7_arr[10] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0};
        
        for (int i = 0; i < L; ++i) {
            if (num[i] == '0') {
                z_idx = min(z_idx, i);
            }
            int d = num[i] - '0';
            int c2 = 0, c3 = 0, c5 = 0, c7 = 0;
            if (d > 0) {
                c2 = c2_arr[d];
                c3 = c3_arr[d];
                c5 = c5_arr[d];
                c7 = c7_arr[d];
            }
            p2[i + 1] = max(0, p2[i] - c2);
            p3[i + 1] = max(0, p3[i] - c3);
            p5[i + 1] = max(0, p5[i] - c5);
            p7[i + 1] = max(0, p7[i] - c7);
        }
        
        if (z_idx == L && p2[L] == 0 && p3[L] == 0 && p5[L] == 0 && p7[L] == 0) {
            return num;
        }
        
        string ans_prefix = "";
        int ans_rem_len = 0;
        int ans_rem2 = 0, ans_rem3 = 0, ans_rem5 = 0, ans_rem7 = 0;
        bool found = false;
        
        int start_idx = min(L - 1, z_idx);
        for (int i = start_idx; i >= 0; --i) {
            int start_d = (num[i] - '0') + 1;
            for (int d = start_d; d <= 9; ++d) {
                int r2 = max(0, p2[i] - c2_arr[d]);
                int r3 = max(0, p3[i] - c3_arr[d]);
                int r5 = max(0, p5[i] - c5_arr[d]);
                int r7 = max(0, p7[i] - c7_arr[d]);
                
                int rem_len = L - 1 - i;
                if (r5 + r7 + get_dp(r2, r3) <= rem_len) {
                    found = true;
                    ans_prefix = num.substr(0, i) + to_string(d);
                    ans_rem_len = rem_len;
                    ans_rem2 = r2;
                    ans_rem3 = r3;
                    ans_rem5 = r5;
                    ans_rem7 = r7;
                    break;
                }
            }
            if (found) break;
        }
        
        if (!found) {
            int min_len = req5 + req7 + get_dp(req2, req3);
            int new_L = max(L + 1, min_len);
            ans_prefix = "";
            ans_rem_len = new_L;
            ans_rem2 = req2;
            ans_rem3 = req3;
            ans_rem5 = req5;
            ans_rem7 = req7;
        }
        
        string res = ans_prefix;
        int curr2 = ans_rem2, curr3 = ans_rem3, curr5 = ans_rem5, curr7 = ans_rem7;
        
        for (int pos = 0; pos < ans_rem_len; ++pos) {
            for (int d = 1; d <= 9; ++d) {
                int r2 = max(0, curr2 - c2_arr[d]);
                int r3 = max(0, curr3 - c3_arr[d]);
                int r5 = max(0, curr5 - c5_arr[d]);
                int r7 = max(0, curr7 - c7_arr[d]);
                
                if (r5 + r7 + get_dp(r2, r3) <= ans_rem_len - 1 - pos) {
                    res += to_string(d);
                    curr2 = r2;
                    curr3 = r3;
                    curr5 = r5;
                    curr7 = r7;
                    break;
                }
            }
        }
        
        return res;
    }
};