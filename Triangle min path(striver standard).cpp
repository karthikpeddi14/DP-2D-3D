// recursion and memoization is same
// tabulation
class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n=triangle.size();
        int dp[n][n];

        for(int i=0 ; i<n ; i++)
        {
            dp[n-1][i] = triangle[n-1][i];
        }

        for(int i=n-2; i>=0 ; i--)
        {
            for(int j=i ; j>=0 ; j--)
            {
                int d = dp[i+1][j];
                int dr = dp[i+1][j+1];
                dp[i][j] = min(d,dr) + triangle[i][j];
            }
        }
        return dp[0][0];
    }
};
//tabulation

//space optimal
class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n=triangle.size();
        vector<int> next(n,0);

        for(int i=0 ; i<n ; i++)
        {
            next[i] = triangle[n-1][i];
        }

        for(int i=n-2; i>=0 ; i--)
        {
            vector<int> cur(n,0);
            for(int j=i ; j>=0 ; j--)
            {
                int d = next[j];
                int dr = next[j+1];
                cur[j] = min(d,dr) + triangle[i][j];
            }
            next = cur;
        }
        return next[0];
    }
};
// space optimal
