#include<bits/stdc++.h>
using namespace std;

// Function to find the index of the previous job whose end time is less than or equal to the current job's start time
int binSrch(vector<vector<int>> v, int n)
{
    // Binary search implementation
    int s = 0,e = n, mid;

    while (s <= e)
    {
        mid = (s + e) / 2;
        if (v[mid][1] <= v[n][0])
        {
            // if you found a job ends before the current one starts
            if (v[mid + 1][1] <= v[n][0]) s = mid + 1;
            // if it wasn't the last one to end before the current continue searching in the second half of the array

            else return mid;
            // if it was the last one return it
        }
        else e = mid - 1;
        // if the ending time was after starting time of the current continue searching in the first half
    }
    return -1;
    // return -1 if no non-conflicting job is found
}



bool cmp(vector<int> a, vector<int> b)
{
    return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
}
// comparing function to sort according to End time


int main()
{
    int n;
    cin>>n;
// number of jobs

    vector<vector<int>> v(n,vector<int>(3));
// Array contain the N jobs starting time, ending time and profit respectively

    for(int i=0; i<n; i++)
    {
        cin>>v[i][0]>>v[i][1]>>v[i][2];
    }
    sort(v.begin(),v.end(), cmp);
// sort jobs in increasing order according to their finish times

    vector<int>dp(n);
// dp[i] stores max profit for jobs from 0 till ith index

    dp[0] = v[0][2];
//initializing array with base case, which is 1st job's profit

    for (int i = 1; i < n; i++)
    {
// find index of the last job ending before/at the start time of the current job using binary search
        int prev = binSrch(v, i);
        int currentProfit = v[i][2]; // profit of this job

        if (prev != -1) currentProfit += dp[prev];
        //if you found a job that ends before this one starts then add its profit

        if (dp[i-1] < currentProfit) dp[i] = currentProfit;
        // if current profit is higher than previous index's profit till ith index keep this

        else dp[i] = dp[i-1];
        // if taking this job won't get greater profit keep the last maximum profit
    }
    cout << "Maximum profit you can get is " <<dp[n-1]<<endl; // maximum profit from the N jobs
    /* Time complexity: O(N logN)
       Space complexity: O(N) */

}
