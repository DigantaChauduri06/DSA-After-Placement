class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int target) {
        int n = m.size();
        int i = 0;
        int j = m[0].size() - 1;
        while (i < n && j >= 0) {
            if (m[i][j] == target) return true;
            if (m[i][j] < target) {
                i++;
            } else {
                j--;
            }
        }
        return false;
    }
};