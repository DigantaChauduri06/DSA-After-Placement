//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    static bool comp(Job &a, Job &b) {
        return a.profit > b.profit;
    }
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)  { 
        // your code here
        int dayMax = 0;
        for (int i = 0; i < n;i++) {
            dayMax = max(dayMax, arr[i].dead);
        }
        vector<int> days(dayMax, -1);
        sort(arr, arr+n, comp);
        int cnt = 0;
        int profit = 0;
        for (int i = 0;i < n;i++) {
            int j = arr[i].dead - 1;
            // bool hasPlace = false;
            while (j >= 0) {
                if (days[j] == -1) {
                    days[j] = arr[i].id;
                    profit += arr[i].profit;
                    cnt++;
                    // hasPlace = true;
                    break;
                }
                j--;
            }
            // if (!hasPlace) {
            //     return {cnt, profit};
            // }
        }
        return {cnt, profit};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends