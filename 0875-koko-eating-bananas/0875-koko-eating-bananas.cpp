class Solution {
    bool canEat(vector<int> &piles, int h, long curS) {
        long curH = 0;
        for (auto p : piles) {
            curH += ceil(static_cast<double>(p) / curS);
        }
        return curH <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int minSpeed = 1;
        int maxSpeed = *max_element(piles.begin(), piles.end());
        while (minSpeed <= maxSpeed) {
            long mid = minSpeed + (maxSpeed - minSpeed) / 2;
            if (canEat(piles, h, mid)) {
                maxSpeed = mid-1;
            } else {
                minSpeed = mid+1;
            }
        }
        return minSpeed;
    }
};