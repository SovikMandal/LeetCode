class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        int ans = 10;
        int available = 9;
        int maxPossibleCnt = 9;
        for(int i = 2; i <= n && available > 0; i++) {
            maxPossibleCnt *= available;
            ans += maxPossibleCnt;
            available--;
        }

        return ans;
    }
};