//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
    vector<int> ans;
    int sm = 0;
    void helper(vector<int> &arr, int N, int i) {
        if (i >= N) {
            // ans.push_back(sm);
            ans.push_back(sm);
            return;
        }
        sm += arr[i];
        helper(arr, N, i+1);
        sm -= arr[i];
        helper(arr, N, i+1);
    }
    
public:
    vector<int> subsetSums(vector<int> arr, int N) {
        // Write Your Code here
        helper(arr, N, 0);
        sort(ans.begin(), ans.end());
        // cout << ans.size() << endl;
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends