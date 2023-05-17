#include <bits/stdc++.h>
using namespace std;

int problemB (vector<vector<int>>& v)
{
    int n= v.size();
    sort(v.begin(),v.end());
// sorting according to starting time then ending time then profit

    int x,mx=0;
// variables to store maximum profit

    for(int i=1; i<n; i++)
    {
        x=0;
        for(int j=0; j<i; j++)
        {
// iterating through all the previous jobs

            if(v[j][1]<=v[i][0]) x=max(x,v[j][2]);
        }
        // looking for the jobs that end before this one starts and store the maximum accumulative profit

        v[i][2]+=x;
        /* after getting the maximum accumulative profit from the previous jobs
        ending before/at its starting time add it to this job's profit*/

        mx=max(mx,v[i][2]);
// storing the maximum accumulative profit till now
    }
    return mx;
// Printing the maximum profit you can get

    /* Time Complexity: O(N^2)
     Space Complexity: O(N) */
}
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
// getting the input
    cout << "The maximum profit you can get is : " << problemB(v) << endl;
}
}
