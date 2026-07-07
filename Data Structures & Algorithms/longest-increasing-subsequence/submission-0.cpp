class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size()) ; 
        dp[0] = 1 ; 
        int ans  = 1; 
        for (int i = 1 ; i<nums.size() ; i++) {
            int max_prev = 0 ;
            for (int u = i-1 ; u>=0 ; u--) {
                if (nums[u] < nums[i]) {
                    max_prev = max( max_prev , dp[u]) ; 
                }
            }
            dp[i] = 1 + max_prev ;
            ans = max(ans , dp[i]) ;  
        }
        return ans ; 

    }
};
