class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       unordered_map<int, int> mpp;
        for (int i = 0;i < nums2.size();i++) {
            mpp[nums2[i]] = i;
        }
        vector<int> ans;
        for (auto &num : nums1) {
            int idx = mpp[num];
            idx+=1;
            int tmp = -1;
            while (idx < nums2.size()) {
                if (nums2[idx] > num) {
                    tmp = nums2[idx];
                    break;
                }
                idx+=1;
            }
            ans.push_back(tmp);
            
        }
        return ans;
    }
};
/*
1 -> 0
3 -> 


*/