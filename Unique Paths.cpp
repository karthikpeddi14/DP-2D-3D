//recursion and memoization
#include <bits/stdc++.h> 
int ans(int r, int c,vector<vector<int>>& dp)
{
	if(r==1 || c==1) return 1;
	if(dp[r-1][c-1]!=0) return dp[r-1][c-1];
	
	int count = ans(r-1,c,dp) + ans(r,c-1,dp);
	dp[r-1][c-1] = count;
	return count;
}
int uniquePaths(int m, int n) {
	vector<vector<int>> dp(m,vector<int>(n,0));
	return ans(m,n,dp);
}
//recursion and memoization

//tabulation
#include <bits/stdc++.h> 
// consider dp to be filled and it gives the answer for certain i,j

int uniquePaths(int m, int n) {
	
	int dp[m][n];
	for(int i=0 ;i<m ; i++)
	{
		for(int j=0 ; j<n ; j++)
		{
			if(i==0 && j==0) dp[i][j] = 1;
			else
			{
				int right = 0;
				int down = 0;
				if(j>0) right = dp[i][j-1];
				if(i>0) down = dp[i-1][j];
				dp[i][j] = right+down;
			}
		}
	}
	return dp[m-1][n-1];
}
//tabulation

// space optimum
class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        vector<int> prev(n,0);

        for(int i=0 ; i<m; i++)
        {
            vector<int> cur(n,0);
            for(int j=0 ; j<n ; j++)
            {
                if(i==0 && j==0)
                {
                    cur[j] = 1;
                    continue;
                }
                int left = 0;
                int up = 0;
                if(j>0) left = cur[j-1];
                if(i>0) up = prev[j];
                cur[j] = left+up;
            }
            prev = cur;
        }
        return prev[n-1];
    }
};
// space optimum
