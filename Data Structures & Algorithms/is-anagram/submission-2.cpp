class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        vector<int> freq(26,0) ; 
        for (auto i : s ) {
            freq[i - 'a']++ ; 
        }
        for (auto i : t) {
            freq[i - 'a']-- ; 

        }
        for (auto i : freq) {
            if (i != 0 ) {
                return false ;
            }
        }
        return true ;
        
        
    }
};
