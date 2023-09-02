class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int x = mat[0].size() - 1;
        int y = 0;
        while (x >= 0 && y < mat.size()) {
            if (mat[y][x] == target) return true;
            else if (mat[y][x] > target) x--;
            else y++;
        }
        return false;
    }
};