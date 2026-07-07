class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict ; 
        int maxlen = 0 ;
        int minlen = INT_MAX ; 
        for (auto &u : wordDict) {
            maxlen = max(int(u.size()) , maxlen) ; 
            minlen = min(int(u.size()) , minlen) ;
            dict.insert(u) ; 
        }
        vector<int> dp(s.size() + 1  , -1) ; 
        dp[0] = 1 ;
        for (int i = 1 ; i<s.size()+1 ; i++ ) {
            if (dp[i-1] == -1) continue ; 
            string word ; 
            for (int u = i ; u-i + 1 <= maxlen && u <s.size() +1  ; u++) {
                  word.push_back(s[u-1]) ;
                  if (dict.count(word)) dp[u] = 1 ; 
            } 
        }
        if(dp[s.size()] == 1) return true ;
        else return false ; 
    }
};
