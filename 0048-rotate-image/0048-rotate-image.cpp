class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int n = m.size();
        // Reversed with rows with column
        for (int i = 0;i < n;i++) {
            for (int j = i;j < n;j++) {
                if (i==j) continue;
                swap(m[i][j], m[j][i]);
            }
        }
        // reverse each column
        for (int i = 0;i < m.size();i++) {
            reverse(m[i].begin(), m[i].end());
        }
    }
};