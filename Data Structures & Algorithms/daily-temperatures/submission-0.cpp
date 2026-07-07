class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st  ;
        vector<int> result(temperatures.size() , 0) ; 
        for (int i = 0 ; i< temperatures.size() ; i++) {
            if(!st.empty()) {
                while(temperatures[i] > st.top().first) {
                    result[st.top().second] = i - st.top().second ; 
                    st.pop();
                    if(st.empty()) break ;
                }
            }
            st.push({temperatures[i] , i}) ; 
        }
        return result;
        
    }
};
