class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st ; 
        for (auto u :tokens ) {
             if (u == "+") {
                int x = st.top() ;
                st.pop() ; 
                int y = st.top() ; 
                st.pop();
                int z = x + y ; 
                st.push(z);
            }
            else if (u == "-") {
                int x = st.top() ;
                st.pop() ; 
                int y = st.top() ; 
                st.pop();
                int z = y - x ; 
                st.push(z);
                
            }
            else if (u == "*") {
                int x = st.top() ;
                st.pop() ; 
                int y = st.top() ; 
                st.pop();
                int z = x * y ; 
                st.push(z);
                
            }
            else if (u == "/") {
                int x = st.top() ;
                st.pop() ; 
                int y = st.top() ; 
                st.pop();
                int z = y / x ; 
                st.push(z);
            }   
            else {
                st.push(stoi(u));
            }                    
        }
        return st.top();
    }
};
