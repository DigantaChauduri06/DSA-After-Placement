class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, h = nums.size() - 1;
        while (l < h) {
            int m = l + (h - l) / 2;
            // right part is un sorted
            if (nums[h] < nums[m]) {
                l = m + 1;
            }
            else {
                h = m;
            }
        }
        return nums[l];
    }
};