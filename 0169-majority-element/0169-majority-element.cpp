class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cur = nums[0];
        int cnt = 1;
        for (int i = 1;i < nums.size();i++) {
            if (nums[i] == cur) {
                cnt += 1;
            } else {
                cnt -= 1;
            }
            if (cnt == 0) {
                cnt = 1;
                cur = nums[i];
            }
        }
        return cur;
    }
};