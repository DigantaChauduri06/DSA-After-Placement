class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0;i < n-3;i++) {
            for (int j = i+1;j < n-2;j++) {
                for (int k = j+1;k < n-1;k++) {
                    int st = k+1, ed = n - 1;
                    while (st <= ed) {
                        int m = (st + ed) / 2;
                        long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[k] + (long long)nums[m];
                        if (sum == target) {
                            ans.push_back({nums[i], nums[j], nums[k], nums[m]});
                            break;
                        }
                        else if (sum > target) {
                            ed--;
                        } else {
                            st++;
                        }
                    }
                    while (k < n - 1 && nums[k] == nums[k+1]) k+=1;
                }
                while (j < n - 1 && nums[j] == nums[j+1]) j+=1;
            }
            while (i < n - 1 && nums[i] == nums[i+1]) i+=1;
        }
        return ans;
    }
};