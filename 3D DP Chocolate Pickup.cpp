// recursion and memoization
#include <bits/stdc++.h> 
int recur(vector<vector<int>> &grid, int r ,int c1, int c2,vector<vector<vector<int>>>& dp)
{
   if(c1<0 || c1>=grid[0].size() || c2<0 || c2>=grid[0].size()) return -1e8;
   if(dp[r][c1][c2]!=-1) return dp[r][c1][c2]; 
   if(r==grid.size()-1)
   {
       if(c1==c2) return grid[r][c1];
       return grid[r][c1] + grid[r][c2];
   }
   int maxi = 0;
   for(int i=-1 ; i<=1; i++)
   {
       for(int j=-1 ; j<=1; j++)
       {
           int value;
           if(c1==c2) value =grid[r][c1];
           else value = grid[r][c1] +grid[r][c2];
           value += recur(grid,r+1,c1+i,c2+j,dp);
           maxi = max(maxi,value);
       }
   }
   return dp[r][c1][c2] = maxi;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) 
{
    vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int> (c,-1)));
    return recur(grid,0,0,grid[0].size()-1,dp);
}
//recursion and memoization

// tabulation
#include <bits/stdc++.h> 

int maximumChocolates(int r, int c, vector<vector<int>> &grid) 
{
    int dp[r][c][c];
    for(int j1=0 ; j1<c; j1++) 
    {
        for(int j2=0 ; j2<c; j2++)
        {
            if(j1==j2) dp[r-1][j1][j1]  = grid[r-1][j1];
            else dp[r-1][j1][j2] = grid[r-1][j1] + grid[r-1][j2];
        }
    }

    for(int i=r-2 ; i>=0 ; i--)
    {
        for(int c1=0 ; c1<c ; c1++)
        {
            for(int c2=0; c2<c; c2++)
            {
                int maxi=0;
                for(int d1=-1; d1<=1; d1++)
                {
                    for(int d2=-1; d2<=1; d2++)
                    {
                        int value;
                        if(c1==c2) value = grid[i][c1];
                        else value = grid[i][c1] + grid[i][c2];
                        if(c1+d1>=0 && c2+d2>=0 && c1+d1<c && c2+d2<c) value += dp[i+1][c1+d1][c2+d2];
                        maxi = max(maxi,value);
                    }
                }
                dp[i][c1][c2] = maxi;
            }
        }
    }
    return dp[0][0][c-1];

}
//tabulation

// space optimum
#include <bits/stdc++.h> 

int maximumChocolates(int r, int c, vector<vector<int>> &grid) 
{
    vector<vector<int>> next(c,vector<int> (c,0));
    for(int j1=0 ; j1<c; j1++) 
    {
        for(int j2=0 ; j2<c; j2++)
        {
            if(j1==j2) next[j1][j1]  = grid[r-1][j1];
            else next[j1][j2] = grid[r-1][j1] + grid[r-1][j2];
        }
    }

    for(int i=r-2 ; i>=0 ; i--)
    {
        vector<vector<int>> cur(c,vector<int> (c,0));
        for(int c1=0 ; c1<c ; c1++)
        {
            for(int c2=0; c2<c; c2++)
            {
                int maxi=0;
                for(int d1=-1; d1<=1; d1++)
                {
                    for(int d2=-1; d2<=1; d2++)
                    {
                        int value;
                        if(c1==c2) value = grid[i][c1];
                        else value = grid[i][c1] + grid[i][c2];
                        if(c1+d1>=0 && c2+d2>=0 && c1+d1<c && c2+d2<c) value += next[c1+d1][c2+d2];
                        maxi = max(maxi,value);
                    }
                }
                cur[c1][c2] = maxi;
            }
        }
        next = cur;
    }
    return next[0][c-1];

}
//space optimum
