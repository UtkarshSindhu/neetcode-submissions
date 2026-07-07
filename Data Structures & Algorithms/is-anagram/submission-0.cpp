class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq(256,0) ; 
        for (auto i : s ) {
            freq[i]++ ; 
        }
        for (auto i : t) {
            freq[i]-- ; 

        }
        for (auto i : freq) {
            if (i != 0 ) {
                return false ;
            }
        }
        return true ;
        
        
    }
};
