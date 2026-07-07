class Solution {
public:
    int trap(vector<int>& height) {
        int sz = height.size() ; 
        int ans = 0 ; 
        vector<int> prefixMax(sz) ; 
        vector<int> suffixMax(sz) ; 
        prefixMax[0] = height[0] ; 

        for (int i = 1 ; i < sz ; i++) {
              prefixMax[i] = max(prefixMax[i-1] , height[i]) ; 
        }
        suffixMax[sz-1] = height[sz-1] ;
        for (int i = sz-2 ; i>=0 ; i--) {
              suffixMax[i] = max(suffixMax[i+1], height[i]);   
        }
        for (int i = 1 ; i <sz-1 ; i++) {
            int trappedWater = min(prefixMax[i] , suffixMax[i]) - height[i] ; 
            ans+= trappedWater ; 

        }
        return ans ; 
    }
};
