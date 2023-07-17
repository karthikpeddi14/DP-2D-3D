// recursion and memoization
class Solution {
public:
    int ans(vector<vector<int>>& obstacleGrid, int r, int c,vector<vector<int>>& dp)
    {
        if(r<0 || c<0 || obstacleGrid[r][c] == 1) return 0;
        if(r==0 && c==0) return 1;
        if(dp[r][c]!=-1) return dp[r][c];
        
        return dp[r][c] = ans(obstacleGrid,r-1,c,dp) + ans(obstacleGrid,r,c-1,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n= obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return ans(obstacleGrid,m-1,n-1,dp);
    }
};
// recursion and memoization

// tabulation
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n= obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        for(int i=0 ; i<m ; i++)
        {
            for(int j=0; j<n ; j++)
            {
                if(obstacleGrid[i][j]==1) dp[i][j] = 0;
                else if(i==0 && j==0) dp[i][j] = 1;
                else
                {
                    int left = 0;
                    int up = 0;
                    if(j>0) left = dp[i][j-1];
                    if(i>0) up = dp[i-1][j];
                    dp[i][j] = left + up;
                }
            }
        }
        return dp[m-1][n-1];
    }
};
//tabulation

// space optimum
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n= obstacleGrid[0].size();
        vector<int> prev(n,0);

        for(int i=0 ; i<m ; i++)
        {
            vector<int> cur(n,0);
            for(int j=0; j<n ; j++)
            {
                if(obstacleGrid[i][j]==1) cur[j] = 0;
                else if(i==0 && j==0) cur[j] = 1;
                else
                {
                    int left = 0;
                    int up = 0;
                    if(j>0) left = cur[j-1];
                    if(i>0) up = prev[j];
                    cur[j] = left + up;
                }
            }
            prev = cur;
        }
        return prev[n-1];
    }
};
//space optimum
