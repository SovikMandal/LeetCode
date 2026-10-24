class Solution:
    def smallerNumbersThanCurrent(self, nums: list[int]) -> list[int]:
        res = []
        for i in nums:
            count = 0
            currVal = i
            for j  in nums:
                if currVal > j:
                    count += 1
            res.append(count)
        return res