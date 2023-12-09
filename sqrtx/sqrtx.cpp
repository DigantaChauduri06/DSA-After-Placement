class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;
        int low = 1;
        int high = x / 2 + 1;
        int ans = -1;
        while (low <= high) {
            long long m = low + (high - low) / 2;
            if (m*m == x) return m;
            if (m*m > x) {
                high = m - 1;
            }
            else {
                ans = m;
                low = m + 1;
            }
        }
        return ans;
    }
};