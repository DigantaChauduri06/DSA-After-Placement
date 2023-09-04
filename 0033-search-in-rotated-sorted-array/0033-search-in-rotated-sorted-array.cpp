class Solution {
    int pivotIndex(vector<int> &nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            // we need to find the half
            int mid = low + (high - low) / 2;
            // we are in the wrong half
            if (nums[mid] > nums[high]) {
                low = mid+1;
            } else {
                high = mid;
            }
        }
        return low;
    }
    int binary_search(vector<int> &nums, int l, int h, int target) {
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (nums[m] == target) return m;
            if (nums[m] > target) h = m-1;
            else l = m+1;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int pivot = pivotIndex(nums);
        if (nums[pivot] == target) return pivot;
        int left = binary_search(nums, 0, pivot - 1, target);
        return left == -1 ? binary_search(nums, pivot+1, nums.size()-1, target) : left;
    }
};
/*
    [4,5,6,7,0,1,2]
    
    
*/