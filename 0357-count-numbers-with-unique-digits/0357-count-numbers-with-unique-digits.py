class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        if(n == 0):
            return 1
        ans = 10
        maxPossibleCnt = 9
        available = 9
        i = 2
        while i <= n and available > 0:
            maxPossibleCnt *= available
            ans += maxPossibleCnt
            available -= 1
            i += 1
        return ans
            