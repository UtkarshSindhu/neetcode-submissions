class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size() , vector<int>(amount +1 , 0)) ;
        for (int i = 0 ; i<=amount ; i = i + coins[0]) {
            dp[0][i] = 1 ;
        }
        for (int i = 0 ; i<coins.size() ; i ++) {
            dp[i][0] = 1 ;
        }
        for (int i = 1 ; i<coins.size() ; i++) {
            for(int u = 1 ; u<=amount ; u++) {
                if(u-coins[i] >=0 ) {
                    dp[i][u] += dp[i][u-coins[i]] ;
                }
                dp[i][u] += dp[i-1][u];
            }
        }
        return dp[coins.size()-1][amount] ; 


    }
};
