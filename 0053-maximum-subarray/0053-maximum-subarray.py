class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxSoFar,curSum = -1e9,0
        for n in nums:
            curSum+=n
            maxSoFar = max(maxSoFar, curSum)
            if curSum < 0:
                curSum = 0
        return maxSoFar