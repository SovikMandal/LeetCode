class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const long long MOD = 1000000007;
        int n = s.size();

        vector<int> idx(n + 1, 0);
        vector<long long> val(n + 1, 0);
        vector<long long> tot(n + 1, 0);
        vector<long long> pow10(n + 1, 1);

        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        int c = 0;

        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';
            if (d != 0) {
                c++;
                val[c] = (val[c - 1] * 10 + d) % MOD;
                tot[c] = tot[c - 1] + d;
            }
            idx[i + 1] = c;
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {
            int l = q[0], r = q[1];

            int a = idx[l];
            int b = idx[r + 1];

            if (a == b) {
                ans.push_back(0);
                continue;
            }

            int len = b - a;

            long long num = (val[b] - val[a] * pow10[len]) % MOD;
            if (num < 0) num += MOD;

            long long sumDigits = tot[b] - tot[a];

            ans.push_back((num * sumDigits) % MOD);
        }

        return ans;
    }
};