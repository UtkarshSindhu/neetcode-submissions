class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> record  ;
        int left = 0 , right = 0  ; 
        int length =0 ; 
        while (right<s.size()) {
             if (!record.count(s[right])) {
                 record[s[right]] = right ; 
                 length = max(length , right-left+1) ; 
             }
             else {
                int index = record[s[right]] ;
                while (left <= index) {
                    record.erase(s[left]) ; 
                    left++ ; 
                }
                record[s[right]] = right ; 
                length = max(length , right-left+1);
             }
             right++ ; 
        }
        return length ; 
        
    }
};
