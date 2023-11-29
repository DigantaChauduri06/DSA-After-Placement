class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = dip_backwords(nums);
        // If the array is increasingly sorted then just reverse will be answer
        if (index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        // find just larger number than nums[index]
        int index2 = just_larger_from_back(nums, nums[index]);
        // reverse the position in the array
        if (index2 != -1)
            swap(nums[index], nums[index2]);
        // sort the entire array starting from that dip_position + 1
        reverse(nums.begin() + index + 1, nums.end());
    }
private:
    int dip_backwords(vector<int> &nums) {
        int index = -1;
        for(int i = nums.size()-2;i >= 0;i--) {
            if (nums[i] < nums[i+1]) {
                index = i;
                break;
            }
        }
        return index;
    }
    int just_larger_from_back(vector<int> &nums, int num) {
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] > num) {
                return i;
            }
        }
        return -1;
    }

};