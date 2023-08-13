class Solution {
    int dp[1002];
    int minCost(vector<int> &cost, int st) {
        if (st >= cost.size()) return 0;
        if (dp[st] != -1) return dp[st];
        int op1 = minCost(cost, st+1) + cost[st];
        int op2 = minCost(cost, st+2) + cost[st];
        return dp[st] = min(op1, op2);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp, -1, sizeof dp);
        return min(minCost(cost, 0), minCost(cost, 1));
    }
};