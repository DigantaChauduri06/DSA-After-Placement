class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        set<pair<int, int>> st;
        for (int i = 0;i < m.size();i++) {
            for (int j = 0;j < m[i].size();j++) {
                if(m[i][j] == 0) {
                    st.insert(make_pair(i, j));
                }
            }
        }
        for (auto &it : st) {
            int f = it.first;
            int s = it.second;
            for (int i = 0; i < m[0].size();i++) {
                m[f][i] = 0;
            }
            for (int j = 0; j < m.size();j++) {
                m[j][s] = 0;
            }
        }
    }
};