class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0, ele1 = INT_MIN, ele2 = INT_MIN;
        for (int i = 0;i < nums.size();i++) {
            if (cnt1 == 0 && nums[i] != ele2) {
                cnt1 = 1;
                ele1 = nums[i];
            } else if(cnt2 == 0 && nums[i] != ele1) {
                cnt2 = 1;
                ele2 = nums[i];
            } else if (nums[i] == ele1) {
                cnt1+=1;
            } else if (nums[i] == ele2) {
                cnt2+=1;
            } else {
                cnt1 -= 1;
                cnt2 -= 1;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        for (int i = 0;i < nums.size();i++) {
            if (nums[i] == ele1) cnt1++;
            if (nums[i] == ele2) cnt2++;
        }
        if (cnt2 > nums.size() / 3  && cnt1 > nums.size() / 3) {
            return {ele1, ele2};
        }
        if (cnt2 > nums.size() / 3) return {ele2};
        if (cnt1 > nums.size() / 3) return {ele1};
        return {};
    }
};