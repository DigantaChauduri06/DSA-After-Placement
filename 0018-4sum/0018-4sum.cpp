class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        for (int i = 0;i < n-3;i++) {
            for (int j = i+1;j < n-2;j++) {
                for (int k = j+1;k < n-1;k++) {
                    int st = k+1, ed = n - 1;
                    while (st <= ed) {
                        int m = (st + ed) / 2;
                        long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[k] + (long long)nums[m];
                        if (sum == target) {
                            ans.insert({nums[i], nums[j], nums[k], nums[m]});
                            break;
                        }
                        else if (sum > target) {
                            ed--;
                        } else {
                            st++;
                        }
                    }
                }
                
            }
        }
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};