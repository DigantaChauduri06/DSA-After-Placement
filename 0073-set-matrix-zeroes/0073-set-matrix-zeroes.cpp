class Solution {
private:
    void nullify_rows(vector<vector<int>> &mat, int col) {
        // cout << "NULLIFY ROWS " << col << " " << mat.size() << endl;
        for (int i = 0;i < mat.size();i++) {
            mat[i][col] = 0;
        }
    }
    void nullify_cols(vector<vector<int>> &mat, int row) {
        // cout << "NULLIFY COLS " << row << " " << mat[0].size() << endl;
        
        for (int i = 0;i < mat[0].size();i++) {
            mat[row][i] = 0;
        }
    }
public:
    void setZeroes(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        int first_cell_is_zero = mat[0][0] == 0; // true
        int first_row = 0; //. true
        int first_col = 0;
        // check first row and first col is there any 0 present or not
        for (int i = 1;i < r;i++) {
            if (mat[i][0] == 0) {
                first_col = 1;
            }
        }
        for (int j = 1;j < c;j++) {
            if (mat[0][j] == 0) {
                first_row = 1;
            }
        }
        for (int i = 1;i < r;i++) {
            for (int j = 1;j < c;j++) {
                if (mat[i][j] == 0) {
                    mat[i][0] = 0;
                    mat[0][j] = 0;
                }
            }
        }
        /// nullify the cols
        for (int i = 1;i < r;i++) {
            if (!mat[i][0])
                nullify_cols(mat, i);
        }
        // nullify the rows
        for (int i = 1;i < c;i++) {
            if (!mat[0][i])
                nullify_rows(mat, i);
        }
        if (first_cell_is_zero) {
            nullify_rows(mat, 0); 
            nullify_cols(mat, 0);
            
        }
        if (first_row) {
            nullify_cols(mat, 0);
        }
        if (first_col) {
            nullify_rows(mat, 0); 
        }
    }
};