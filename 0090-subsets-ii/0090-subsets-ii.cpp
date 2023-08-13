class Solution {
private:
    vector<vector<int>> ans;
    vector<int> temp;
    void subsets(vector<int> &nums, int i) {
        if (i >= nums.size()) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        subsets(nums, i+1);
        while (i+1 < nums.size() && nums[i] == nums[i+1]) i+=1;
        temp.pop_back();
        subsets(nums, i+1);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        subsets(nums, 0);
        return ans;
    }
};