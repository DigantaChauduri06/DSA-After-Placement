class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        nonZeros = 0
        i = 0
        while i < len(nums):
            if nums[i] != 0:
                nums[i],nums[nonZeros] = nums[nonZeros],nums[i]
                nonZeros+=1
            i+=1
        