class Solution {
public:
    int dfs(int i , int x , int size ,vector<int>& nums , vector<vector<int>> & dp ) {
        if (x<0) return 0 ;
        if (dp[i][x] != -1) return dp[i][x] ; 
        if (i == size-1) {
            if (x == nums[size-1] || x == 0) {
                return 1; 
            } 
            else {
                return 0 ;
            }
        }
        dp[i][x] = max(dfs(i+1 , x - nums[i] , size , nums ,dp) , dfs(i+1 , x , size , nums , dp)) ; 
        return dp[i][x] ; 
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0 ; 
        for (auto &u : nums) {
            sum+=u ;
        }
        if (sum % 2 != 0) return false ;
        vector<vector<int>> dp(nums.size() , vector<int>(sum ,-1 )) ;
        int x = dfs (0 , sum/2 , nums.size() , nums ,dp ) ; 
        if(x == 1) return true ;
        else return false ; 
    }
};
