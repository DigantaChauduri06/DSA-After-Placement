class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        unordered_map<int, int> mpp;
        
        int longest = 0;

        for (int num : nums) {
            if (st.find(num) == st.end()) {
                continue;  // Skip if the current number has been processed before
            }

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

            mpp[num] = cur;
            longest = max(longest, cur);
        }

        return longest;
    }
};
