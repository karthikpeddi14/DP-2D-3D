// recursion and memoization
class Solution {
public:
    int ans(vector<vector<int>>& matrix, int m , int n,vector<vector<int>>& dp)
    {
        if(n<0 || n>=matrix.size()) return INT_MAX;
        if(m==0) return matrix[m][n];
        if(dp[m][n]!=-1) return dp[m][n];

        int a = ans(matrix,m-1,n,dp);
        int b = ans(matrix,m-1,n-1,dp);
        int c = ans(matrix,m-1,n+1,dp);

        return dp[m][n] = matrix[m][n] + min(min(a,b),c);
    }
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        int mini = INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0 ; i<n ; i++)
        {
            mini = min(mini,ans(matrix,n-1,i,dp));
        }
        return mini;
    }
};
// recursion and memoization

//tabulation
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        int dp[n][n];

        for(int i=0 ; i<n ; i++)  dp[0][i] = matrix[0][i];
        for(int i=1 ; i<n ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                int up = dp[i-1][j];
                int ld = INT_MAX;
                int rd = INT_MAX;
                if(j>0) ld = dp[i-1][j-1];
                if(j<n-1) rd = dp[i-1][j+1];
                dp[i][j] = matrix[i][j] + min(up,min(ld,rd));
            }
        }
        
        int mini =INT_MAX;
        for(int i=0 ; i<n ; i++)
        {
            mini = min(dp[n-1][i],mini);
        }
        return mini;

    }
};
//tabulation


// space optimum
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        vector<int> prev(n,0);

        for(int i=0 ; i<n ; i++)
        {
            vector<int> cur(n,0);
            for(int j=0 ; j<n ; j++)
            {
                int up = 0;
                int ld = INT_MAX;
                int rd = INT_MAX;
                if(i!=0) 
                {
                    up = prev[j];
                    if(j>0) ld = prev[j-1];
                    if(j<n-1) rd = prev[j+1];
                }
                cur[j] = matrix[i][j] + min(up,min(ld,rd));
            }
            prev = cur;
        }
        
        int mini =INT_MAX;
        for(int i=0 ; i<n ; i++)
        {
            mini = min(prev[i],mini);
        }
        return mini;

    }
};
//space optimum
