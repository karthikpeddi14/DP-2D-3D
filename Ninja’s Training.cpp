// RECURSIONC + MEMOIZATION
#include <bits/stdc++.h>

int recursion(vector<vector<int>> &points, int index, int last, vector<vector<int>>& dp)
{
    if(index<0) return 0;
    if(dp[index][last]!=-1) return dp[index][last];

    int c = INT_MIN;
    int a = points[index][(last+1)%3] + recursion(points,index-1,(last+1)%3,dp);
    int b = points[index][(last+2)%3] + recursion(points,index-1,(last+2)%3,dp);
    if(index==points.size()-1) c = points[index][last] + recursion(points,index-1,last,dp);
    return dp[index][last] = max(a,max(b,c));
    
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    int maxi=INT_MIN;
    vector<vector<int>> dp(n,vector<int>(3,-1));
    return recursion(points, n-1, 2, dp);
}
// RECURSIONC + MEMOIZATION

//TABULATION
#include <bits/stdc++.h>

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n,vector<int>(4,0));
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1],points[0][2]));

    for(int i=1; i<n ; i++)
    {
        for(int last=0; last<4 ; last++)
        {
            int maxi = 0;
            for(int task = 0; task<3; task++)
            {
                if(task!=last)
                {
                    int a = points[i][task] + dp[i-1][task];
                    maxi = max(maxi,a);
                }
            }
            dp[i][last] = maxi;
        }
    }

    return dp[n-1][3];
}
//TABULATION

//SPACE OPTIMAL
#include <bits/stdc++.h>

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n,vector<int>(4,0));
    vector<int> prev(4,0);
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1],points[0][2]));

    vector<int> dummy(4,0);

    for(int i=1; i<n ; i++)
    {
        for(int last=0; last<4 ; last++)
        {
            int maxi = 0;
            for(int task = 0; task<3; task++)
            {
                if(task!=last)
                {
                    int a = points[i][task] + prev[task];
                    maxi = max(maxi,a);
                }
            }
            dummy[last] = maxi;
        }
        for(int i=0; i<4; i++)
        {
            prev[i] = dummy[i];
        }
    }

    return prev[3];
}
//SPACE OPTIMAL
