class Solution {
public:
    int dfs(int i ,vector<int> &dp , vector<int>& prices ) {
        if (dp[i] != -1) return dp[i] ; 
        if (i >= prices.size()-1) return 0 ; 
        dp[i] = dfs(i+1 , dp , prices) ; 
        for (int u = i+1 ; u<prices.size() ; u++) {
            dp[i] = max(dp[i] , prices[u] - prices[i] + dfs(u+2 , dp , prices)) ; 
        }
        return dp[i] ;   
        
    }
    int maxProfit(vector<int>& prices) {
        vector<int> dp(prices.size() +2 , -1) ; 
        return dfs(0 , dp , prices) ; 
    }
};
