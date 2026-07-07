class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size() ; 
        vector<int> freq(2001,0) ; 
        for (auto u : nums) {
            freq[u+1000]++ ;
        }
        vector<vector<int>> count(n+1) ; 
        for (int i = 0 ; i<2001 ; i++) {
            count[freq[i]].push_back(i-1000) ; 
        }
        vector<int> answer ; 
            for (int i = n ; i>0 ; i--) {
                if(k==0) break ; 
                int size = count[i].size() ; 
                if (size!=0) {
                    k -=  size ; 
                    for (int u = 0 ; u <size ; u++ ) {
                        answer.push_back(count[i][u]) ; 
                    }
                }
            
        }
        return answer ;


    }
};
