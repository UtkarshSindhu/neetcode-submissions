class Solution {
public:
    int rows ; 
    int columns ; 
    int dfs(int m,int n ,vector<vector<int>> &dp )  {
        if (m >= rows || n>= columns) return 0 ;

        if (dp[m][n] != -1) return dp[m][n] ; 
        if (m ==  rows-1 || n == columns -1) {
            return 1 ;
        }
        return dp[m][n] = dfs(m+1 , n , dp) + dfs(m , n+1 , dp); 
        
    }
    int uniquePaths(int m, int n) {
         vector<vector<int>> dp (m , vector<int>(n , -1)) ; 
         rows = m ; 
         columns = n ; 

          return dfs(0,0 , dp);

 
    }
};
