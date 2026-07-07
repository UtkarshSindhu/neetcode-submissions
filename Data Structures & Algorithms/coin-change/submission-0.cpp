class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1 ,   1e5) ; 
        dp[0] = 0;
        for (int i = 1 ; i < amount+1 ; i++ ){
            for (auto  u : coins) {
                if (i - u > -1) {
                    dp[i] = min(dp[i] , 1+dp[i-u]) ; 
                }                             
            }
        }
        if (dp[amount] == 1e5) dp[amount] = -1 ; 
        return dp[amount] ; 


    }
};
