class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // vector<vector<int>> anas
        // vector<int> ->  strs[]
        vector<vector<int>> anasList;
        map<vector<int>, vector<string>> mapp;
        vector<vector<string>> ans;
        for (int i = 0;i < strs.size();i++) {
            vector<int> anas(26, 0);
            for (char ch : strs[i]) {
                anas[ch - 'a']++;
            }
            mapp[anas].push_back(strs[i]);
        }
        for (const auto &[_, value] : mapp) {
            ans.push_back(value);
        }
        return ans;
    }
};