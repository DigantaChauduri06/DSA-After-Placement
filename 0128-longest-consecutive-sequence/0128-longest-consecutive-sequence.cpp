class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        unordered_set<int> set(nums.begin(), nums.end());
        int longest = 1;
        for (auto n: nums) {
            // Check in both sides 
            int cnt = 1;
            int num = n;
            while (set.find(num-1) != set.end()) {
                set.erase(num);
                num--;
                cnt++;
            }
            num = n;
            while (set.find(num+1) != set.end()) {
                set.erase(num);
                num++;
                cnt++;
            }
            longest = max(longest, cnt);
        }
        return longest;
    }
};

// [100,3,2,1,4,200,]
