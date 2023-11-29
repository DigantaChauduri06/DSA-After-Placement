class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back(vector<int>{1});
        for (int i = 1;i < numRows;i++) {
            vector<int> temp;
            temp.push_back(1);
            for (int j = 1;j < i;j++) {
                temp.push_back(ans.back()[j-1] + ans.back()[j]);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;
    }
};