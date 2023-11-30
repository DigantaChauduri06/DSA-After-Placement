class Solution {
    static bool comp(vector<int> &a, vector<int> &b) {
        return a[0] < b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& I) {
        sort(I.begin(), I.end(), comp);
        vector<vector<int>> ans;
        ans.push_back(I[0]);
        for(int i = 1;i < I.size();i++) {
            if (ans.back()[1] >= I[i][0]) {
                ans.back()[1] = max(I[i][1], ans.back()[1]);
            } else {
                ans.push_back(I[i]);
            }
        }
        return ans;
    }
};