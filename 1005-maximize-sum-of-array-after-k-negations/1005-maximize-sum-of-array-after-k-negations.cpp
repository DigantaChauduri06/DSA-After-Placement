class Solution {
    int sumOfNumbers(vector<int> &nums) {
        int sum = 0;
        for (int num : nums) {
            sum+=num;
        }
        return sum;
    }
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        // if neg then make that positive 
        // if k % 2 == 0 and no neg then k = 1
        // if k % 2 == 0 and neg present then make them positive
        
        // sort the array
        sort(begin(nums), end(nums));
        
        if (nums[0] >= 0 && k%2 == 0) {
            return sumOfNumbers(nums);
        }
        
        if (nums[0] >= 0 && k%2 != 0) {
            nums[0] = -nums[0];
            return sumOfNumbers(nums);
        }
        
        for (int i = 0;i < nums.size();i++) {
            if (k == 0) break;
            if (nums[i] < 0) {
                nums[i] = -nums[i];
                k--;
            }
        }
        if (k >= 0 && k % 2 == 0) {
            return sumOfNumbers(nums);
        }
        sort(begin(nums), end(nums));
        nums[0] = -nums[0];
        return sumOfNumbers(nums);
        // [-2,-2,0,2,5]
        
    }
};