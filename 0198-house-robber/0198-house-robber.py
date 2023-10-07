class Solution:
    def rob(self, nums: List[int]) -> int:
        prev1, prev2 = 0, 0
        # [prev2, prev1, i, i+1, ...]
        for i in nums:
            _sum = max(prev1, prev2+i)
            prev2 = prev1
            prev1 = _sum            
        return prev1