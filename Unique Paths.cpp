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
