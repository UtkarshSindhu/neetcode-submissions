class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() +1 , vector<int>(text2.size() +1  , 0 )) ; 
        for (int i = 1 ; i<= text1.size() ; i++) {
            for (int u = 1 ; u<= text2.size() ; u++) {
                if (text1[i-1] == text2[u-1]) {
                    dp[i][u] = 1 + dp[i-1][u-1] ; 
                }
                else {
                    dp[i][u] = max(dp[i-1][u] , dp[i][u-1]) ; 
                }
            }
        } 
        return dp[text1.size()][text2.size()] ; 

        
    }
};
