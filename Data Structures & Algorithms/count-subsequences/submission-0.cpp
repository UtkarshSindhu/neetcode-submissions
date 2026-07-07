class Solution {
public:
    int ssize , tsize ; 
    int dfs(int x , int y ,string& s, string& t ,vector<vector<int>>& dp)  { 
        if (y>= tsize) return 1 ; 
        if (x >= ssize ) return 0 ; 
        if(dp[x][y]!= -1 ) return dp[x][y] ; 
        dp[x][y] = 0 ; 
        for (int u = x ; u<ssize ; u++) {
            if(t[y] == s[u]) {
                dp[x][y] += dfs(u+1 , y+1 , s,t,dp) ; 
            }
        }
        return dp[x][y] ; 
    }
    int numDistinct(string s, string t) {
        ssize = s.size() ; 
        tsize = t.size() ; 
        vector<vector<int>> dp(ssize , vector<int>(tsize, -1)) ;
        return dfs(0,0,s,t,dp) ;  
        
    }
};
