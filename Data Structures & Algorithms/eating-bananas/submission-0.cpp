class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int ans ;
        int l = 1 ;
        int r = 1000000000  ;
        while (l<=r) {
            int rate =  (l+r)/2 ;
            int hours = 0 ;
            for (auto &u : piles) {
                hours += (u/rate + min(1 , u%rate) ) ; 
            }
            if (hours > h ) l = rate+1 ;
            if (hours <= h) r = rate-1; 
        }
        return r+1 ;  
    }
};
