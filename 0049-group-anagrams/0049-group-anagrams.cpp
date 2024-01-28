class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // vector<vector<int>> anas
        // vector<int> ->  strs[]
        vector<vector<int>> anasList;
        map<vector<int>, vector<string>> mapp;
        vector<vector<string>> ans;
        for (auto &s : strs) {
            vector<int> anas(26, 0);
            for (char ch : s) {
                anas[ch - 'a']++;
            }
            anasList.push_back(anas);
        }
        for (int i = 0;i < anasList.size();i++) {
            mapp[anasList[i]].push_back(strs[i]);
        }
        for (const auto &[_, value] : mapp) {
            ans.push_back(value);
        }
        return ans;
    }
};