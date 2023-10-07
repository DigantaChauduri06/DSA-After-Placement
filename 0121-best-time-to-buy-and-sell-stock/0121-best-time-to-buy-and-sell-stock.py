class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        buy, sell, profit = prices[0],0,0
        for p in prices:
            profit = max(sell - buy, profit)
            buy = min(p, buy)
            sell = max(buy, p)
        return max(profit, sell - buy)