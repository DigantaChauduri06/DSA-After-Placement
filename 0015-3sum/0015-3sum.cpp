class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(begin(nums), end(nums));
        int n = nums.size();
        for (int i = 0;i < n - 1;i++) {
            int si = i+1, ei = n - 1;
            while (si < ei) {
                int sum = nums[si] + nums[ei] + nums[i];
                if (sum == 0) {
                    ans.push_back({nums[si], nums[ei], nums[i]});
                    si++;
                    ei--;
                    while (si < ei && nums[si] == nums[si - 1]) si++;
                    while (si < ei && nums[ei] == nums[ei + 1]) ei--;
                } else if (sum < 0) {
                    si++;
                } else {
                    ei--;
                }
            }
            while (i + 1 < n && nums[i] == nums[i+1])i++;
        }
        return ans;
    }
};