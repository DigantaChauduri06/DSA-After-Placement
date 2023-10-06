class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return -1e9
        cnt,mej = 0,1e9
        for n in nums:
            if cnt == 0:
                cnt+=1
                mej = n
            else:
                if n == mej:
                    cnt+=1
                else:
                    cnt-=1
        return mej
            
        