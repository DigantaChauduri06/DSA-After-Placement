//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n) {
    	// Your code here
    	vector<vector<int>> pairs;
    	priority_queue<int, vector<int>, greater<int>> pq; 
    	for (int i = 0;i < n;i++) {
    	    pairs.push_back({arr[i], dep[i]});
    	}
    	sort(pairs.begin(), pairs.end());
    	int plat = 1;
    	pq.push(pairs[0][1]);
    	for (int i = 1;i < n;i++) {
    	    int top = pq.top();
    	    if (top < pairs[i][0]) {
    	        pq.pop();
    	        pq.push(pairs[i][1]);
    	    } else {
    	        plat++;
    	        pq.push(pairs[i][1]);
    	    }
    	}
    	return plat;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends