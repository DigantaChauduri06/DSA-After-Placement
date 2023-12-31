//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    static bool comp(vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    }
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n) {
        // Your code here
        vector<vector<int>> pairs;
        for (int i = 0;i < n;i++) {
            pairs.push_back({start[i], end[i]});
        }
        sort(pairs.begin(), pairs.end(), comp);
        int cnt = 1;
        int lastEnd = pairs[0][1];
        // cout << lastEnd << endl;
        for (int i = 1;i < n;i++) {
            if (pairs[i][0] > lastEnd) {
                cnt++;
                lastEnd = pairs[i][1];
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends