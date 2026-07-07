class Solution {
public: 
    int specialnode  ; 

    vector<pair<int,int>> cycle_edges ; 
    bool dfs(int node , int parent , vector<vector<int>> &adjlist  , vector<int> &visited) {
        visited[node] = 1 ;
        for (auto &u : adjlist[node] ) {
            if (u== parent) continue ; 
            if(visited[u]) {
                specialnode = u ;
                cycle_edges.push_back({u , node}) ; 
                return false ;
            }
            if (!dfs(u , node , adjlist , visited)) {
                if (u != specialnode) {
                    cycle_edges.push_back({u , node}) ; 
                    return false ; 
                }
                else {
                    return false ;
                }
                
            }
        }
        return true  ; 
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> adjlist(edges.size() + 1 ) ;
        for (auto &u : edges) {
            adjlist[u[0]].push_back(u[1]) ; 
            adjlist[u[1]].push_back(u[0]) ;
        }
        vector<int> visited(edges.size() + 1 , 0) ; 
        dfs(1 , -1 , adjlist , visited) ; 
        set<pair<int,int>> cycle ;
        for (auto &u : cycle_edges) {
            cycle.insert(u) ; 
        }
        for (int i = edges.size() -1 ; i >=0 ; i--) {
            if (cycle.count({edges[i][0] , edges[i][1]}) || cycle.count({edges[i][1] , edges[i][0]})) {
                return edges[i] ; 
            }
        }
 
    }
};
