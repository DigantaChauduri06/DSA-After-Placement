class Solution {
    void helper(vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp, int i) {
        if (i == nums.size()) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        helper(nums, ans, temp, i+1);
        while (i+1 < nums.size() && nums[i] == nums[i+1]) i++;
        temp.pop_back();
        helper(nums, ans, temp, i+1);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        helper(nums, ans, temp, 0);
        return ans;
    }
};