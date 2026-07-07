class Solution {
public:
    int rob(vector<int>& nums) {
          vector<int> dp(nums.size()) ; 
          if (nums.size() == 0 ) return 0 ;
          if (nums.size() == 1 ) return nums[0] ; 
          dp[0] = nums[0] ; 
          dp[1] = max(nums[0] , nums[1]) ; 
          for(int i = 2 ; i < nums.size() -1 ; i ++) {
            dp[i] = max(dp[i-1] , nums[i] + dp[i-2]) ;
          }
          vector<int> dp2(nums.size()) ; 
          dp2[0] = 0 ;
          dp2[1] = max(0 , nums[1]) ; 
          for(int i = 2 ; i < nums.size()  ; i ++) {
            dp2[i] = max(dp2[i-1] , nums[i] + dp2[i-2]) ;
          }
          return max(dp[nums.size() -2] , dp2[nums.size()-1]);

        
    }
};
