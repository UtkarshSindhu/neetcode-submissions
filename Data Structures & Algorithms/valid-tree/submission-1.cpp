class Solution {
public:
    bool dfs(vector<vector<int>> & adjlist  , int  node , int parent , vector<int> &visited) {
        visited[node] = 1 ; 
        for (auto &u : adjlist[node]) {
            if (u!= parent) {
                if (visited[u]) return false ; 
                dfs(adjlist , u , node , visited ) ;
            }
        }
        return true ; 
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjlist(n) ; 
        for (auto &u : edges) {
            if (u[0] == u[1]) return false ;
            adjlist[u[0]].push_back(u[1]) ; 
            adjlist[u[1]].push_back(u[0]) ; 
        }
        vector<int> visited(n , 0) ;
        if (!dfs(adjlist , 0 , 0 , visited)) return false ; 
        for (auto &u : visited) {
            if (u == 0) return false ;
        }
        return true ; 



    }
};
