class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(cand, target, ans, temp, 0, 0);
        return ans;
    }
private:
    void helper(vector<int>& cand, int target, vector<vector<int>> &ans,vector<int> &temp, int i, int sum) {
        if (i == cand.size()) {
            if (sum == target) {
                ans.push_back(temp);
            }
            return;
        }
        if (sum > target) return;
        if (sum == target) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(cand[i]);
        helper(cand, target, ans, temp, i, sum + cand[i]);
        temp.pop_back();
        helper(cand, target, ans, temp, i+1, sum);
    }
};