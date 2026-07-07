class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0   ,right = s.size()-1 ; 
        if (s.size() == 1) return true ; 
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        while (left<right) {
            while(!((s[left] - 'a' < 26 && s[left] - 'a' >= 0)|| (s[left] - '0' <= 9 && s[left] - '0' >=0))){
                left++ ; 
                if(left == s.size()-1) return true ;
            }

            while(!((s[right] - 'a' < 26 && s[right] - 'a' >= 0)|| s[right] - '0' <= 9 && s[right] - '0' >=0)){
               right-- ; 
                if(right == 0) return true ;
            }
            if (left>=right) return true ; 
            if (s[left] == s[right]) {
                left++ ;
                right-- ;
                continue ; 
            }
            else {
                return false ;
            }

        }
        return true ; 

        
    }
};
