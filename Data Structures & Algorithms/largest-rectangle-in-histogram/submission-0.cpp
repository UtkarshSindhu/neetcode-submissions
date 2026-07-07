class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> st ; 
        int answer = 0 ; 

        for (int i = 0 ; i<heights.size() ; i++) {
            while (!st.empty() && heights[i] < st.top().first) {
                   pair<int,int> x = st.top() ; 
                   st.pop() ; 
                   int area ;
                   if (!st.empty())  area = x.first*(i - st.top().second - 1) ;
                   else  area = x.first*(i );
                   answer = max(answer,area) ; 
            }
            st.push({heights[i],i}) ; 
        }
        while (!st.empty()) {
            pair<int,int> x = st.top() ; 
                   st.pop() ; 
                   int area ;
                  if(!st.empty())  area = x.first*(heights.size()   - st.top().second - 1) ;
                   else  area = x.first*(heights.size() ) ; 
                   answer = max(answer,area) ; 
        }
        return answer ;
        
    }
};
