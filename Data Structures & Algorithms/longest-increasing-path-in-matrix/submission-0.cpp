class Solution {
public:
    int rows ; 
    int columns ; 
    vector<pair<int,int>> directions = {{1,0} , {-1,0} , {0,1} , {0,-1}} ; 
    int dfs(int row ,int column , vector<vector<int>>& matrix ,vector<vector<int>>& dp) {
           if(dp[row][column] != -1) return dp[row][column] ; 
           dp[row][column] = 1 ;
           for (auto [r , c] : directions) {         
               if(row +r < rows  && row + r >=0  && column + c < columns  && column + c >= 0 && matrix[row+r][column+c] > matrix[row][column] ) {
                  dp[row][column] = max ( dp[row][column] , 1 + dfs(row+r , column+c , matrix , dp )) ; 
               }
           }
           return dp[row][column] ; 
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        rows = matrix.size() ; 
        columns = matrix[0].size() ; 
        vector<vector<int>> dp(rows , vector<int>(columns,-1)) ; 
        int ans = 1 ; 
        for (int i = 0 ; i<rows ; i++) {
            for (int u = 0 ; u<columns ; u++) {
                ans = max(ans , dfs(i , u , matrix , dp )) ; 
            }
        }
        return ans  ; 
        
    }
};
