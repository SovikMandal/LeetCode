class Solution:
    def missingNumber(self, nums: list[int]) -> int:
        n = len(nums)
        actualSum = (n * (n + 1) // 2)
        currSum = 0
        for i in nums:
            currSum += i
        return actualSum - currSum