class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0, end = height.size() - 1;
        int mx = 0;
        while (start < end) {
            int dist = end - start;
            mx = max(mx, dist * min(height[start], height[end]));
            if (height[start] > height[end]) {
                end--;
            } else {
                start++;
            }
        }
        return mx;
    }
};
/*
     [1,8,6,2,5,4,8,3,7]
     [0,1,2,3,4,5,6,7,8]
*/