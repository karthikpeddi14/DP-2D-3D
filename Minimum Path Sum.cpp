// recursion and memoization
class Solution {
public:
    int ans(vector<vector<int>>& grid, int r, int c,vector<vector<int>>& dp)
    {
        if(r==0 && c==0) return grid[0][0];
        if(r<0 || c<0) return INT_MAX;
        if(dp[r][c]!=-1) return dp[r][c];

        int left = ans(grid,r,c-1,dp);
        int up = ans(grid,r-1,c,dp);

        return dp[r][c] = min(left,up) + grid[r][c];
    }
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m= grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return ans(grid,m-1,n-1,dp);
    }
};
// recursion and memoization

// tabulation
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m= grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));

        for(int i=0 ; i<m ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                if(i==0 && j==0) dp[i][j] = grid[i][j];
                else
                {
                    int left = INT_MAX;
                    int up = INT_MAX;
                    if(j>0) left = dp[i][j-1];
                    if(i>0) up = dp[i-1][j];
                    dp[i][j] = grid[i][j]+ min(left,up);
                }
            }
        }
        return dp[m-1][n-1];
    }
};
// tabulation

// space optimum
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m= grid.size();
        int n = grid[0].size();
        vector<int> prev(n,0);

        for(int i=0 ; i<m ; i++)
        {
            vector<int> cur(n,0);
            for(int j=0 ; j<n ; j++)
            {
                if(i==0 && j==0) cur[j] = grid[i][j];
                else
                {
                    int left = INT_MAX;
                    int up = INT_MAX;
                    if(j>0) left = cur[j-1];
                    if(i>0) up = prev[j];
                    cur[j] = grid[i][j]+ min(left,up);
                }
            }
            prev = cur;
        }
        return prev[n-1];
    }
};
// space optimum
