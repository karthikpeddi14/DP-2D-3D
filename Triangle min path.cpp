// recursion and memoization
class Solution {
public:
    int recursion(vector<vector<int>>& triangle, int index, int last, vector<vector<int>>& dp)
    {
        if(index>=triangle.size()) return 0;
        if(dp[index][last]!=-1) return dp[index][last];

        int left = triangle[index][last] + recursion(triangle,index+1,last,dp);
        int right = INT_MAX;
        if(last<index) right = triangle[index][last+1] + recursion(triangle,index+1,last+1,dp);

        return dp[index][last] = min(left,right);
    }
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return recursion(triangle,0,0,dp);
        
    }
};
// recursion and memoization

// tabulation
class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n = triangle.size();
        int dp[n][n];
        int mini = INT_MAX;
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<triangle[i].size(); j++)
            {
                if(i==0 && j==0) dp[i][j] = triangle[i][j];
                else
                {
                    int up = INT_MAX;
                    int up_left = INT_MAX;
                    if(j<triangle[i].size()-1) up = dp[i-1][j];
                    if(j>0) up_left = dp[i-1][j-1];
                    dp[i][j] = min(up,up_left) + triangle[i][j];
                }
                if(i==n-1) mini = min(mini,dp[i][j]);
            }
        }
        return mini;
        
    }
};
//tabulation

//space optimum
class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n = triangle.size();
        vector<int> prev(n,0);
        int mini = INT_MAX;
        for(int i=0 ; i<n ; i++)
        {
            vector<int> cur(n,0);
            for(int j=0 ; j<triangle[i].size(); j++)
            {
                if(i==0 && j==0) cur[j] = triangle[i][j];
                else
                {
                    int up = INT_MAX;
                    int up_left = INT_MAX;
                    if(j<triangle[i].size()-1) up = prev[j];
                    if(j>0) up_left = prev[j-1];
                    cur[j] = min(up,up_left) + triangle[i][j];
                }
                if(i==n-1) mini = min(mini,cur[j]);
            }
            prev = cur;
        }
        return mini;
        
    }
};
// space optimum
