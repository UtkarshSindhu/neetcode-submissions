class Solution {
public:
    void dfs(int node , int parent ,vector<vector<int>> &adjlist , vector<int> &visited ) {
        visited[node] = 1 ; 
        for (auto &u : adjlist[node]) {
            if(u != parent && !visited[u]) {
                  dfs(u , node , adjlist , visited ) ; 
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
          vector<vector<int>> adjlist(n) ; 
          vector<int> visited(n,0) ; 
          int result = 0 ;
          for(auto &u : edges) {
            adjlist[u[0]].push_back(u[1]) ;
            adjlist[u[1]].push_back(u[0]) ; 
          }
          for ( int i = 0 ;i < n ; i++) {
            if (visited[i] == 0 ) {
                dfs(i , -1 , adjlist , visited) ; 
                result++ ; 
            }
          }
          return result ; 
    }
};
