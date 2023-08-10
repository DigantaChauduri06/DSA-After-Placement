class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> mpp;
        vector<int> ans;
        for (auto &num : nums2) {
            while (!st.empty() && st.top() < num) {
                mpp[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        for (auto &n : nums1) {
            if (mpp.find(n) != mpp.end()) {
                ans.push_back(mpp[n]);
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
        
    }
};