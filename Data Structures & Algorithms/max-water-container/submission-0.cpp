class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0  , right = heights.size() - 1 ; 
        int ans = 0 ;
        while (left < right) {
            if (heights[left] <= heights[right]) {
                ans = max(ans , heights[left]*(right-left)) ;
                left++ ; 
            }
            else {
             ans = max(ans , heights[right]*(right-left)) ;
             right-- ; 
            }
        }
        return ans ; 
    }
};
