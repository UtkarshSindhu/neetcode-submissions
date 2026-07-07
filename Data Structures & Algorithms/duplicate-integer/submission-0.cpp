
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
       unordered_set<int> s ; 
       for (auto i : nums) {
           if(s.count(i) == 1 ) {
            return true ;
           } 
            s.insert(i);
         
       }
       return false ;  
        
    }
};