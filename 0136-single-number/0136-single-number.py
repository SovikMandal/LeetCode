class Solution:
    def singleNumber(self, nums: list[int]) -> int:
        missingValue = 0
        for i in nums:
            missingValue = missingValue ^ i
        return missingValue