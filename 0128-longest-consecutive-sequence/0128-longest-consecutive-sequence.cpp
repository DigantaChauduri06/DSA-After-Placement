class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());        
        int longest = 0;

        for (int num : nums) {
            int cur = 1;
            int temp = num;

            // Check for consecutive numbers (both positive and negative)
            while (st.find(temp - 1) != st.end()) {
                st.erase(temp);
                temp -= 1;
                cur += 1;
            }

            temp = num + 1;  // Check for consecutive positive numbers
            while (st.find(temp) != st.end()) {
                st.erase(temp);
                temp += 1;
                cur += 1;
            }
            longest = max(longest, cur);
        }

        return longest;
    }
};
