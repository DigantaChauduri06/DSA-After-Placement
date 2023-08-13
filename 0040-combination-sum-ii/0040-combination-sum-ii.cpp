class Solution {
    vector<vector<int>> ans;
    vector<int> temp;
    void helper(vector<int> &cand, int tar, int i, int sm) {
        if (i >= cand.size()) {
            if (sm == tar)
                ans.push_back(temp);
            return;
        }
        if (cand[i] + sm <= tar) {
            temp.push_back(cand[i]);
            helper(cand, tar, i+1, sm+cand[i]);
            while (i+1 < cand.size() && cand[i] == cand[i+1]) i++;
            temp.pop_back();
        }
        helper(cand, tar, i+1, sm);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(begin(candidates), end(candidates));
        helper(candidates, target, 0, 0);
        return ans;
    }
};