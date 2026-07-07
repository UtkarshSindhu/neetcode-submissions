class Solution {
public:
      void  dfs(pair<int , int> index , vector<vector<int>> & visited ,vector<vector<char>>& grid ) {
            auto [row , column] = index ;
            if (visited[row][column]) return ;
            visited[row][column] = 1 ; 
            if (row) {
                if (!visited[row-1][column] && grid[row-1][column] == '1') {
                    dfs({row-1 , column} , visited , grid) ; 
                }
            }
            if (row != visited.size()-1) {
                if (!visited[row+1][column] &&  grid[row+1][column] == '1') {
                    dfs({row+1 , column} , visited , grid) ; 
                }
            }
            if (column) {
                if (!visited[row][column-1] && grid[row][column-1] == '1') {
                    dfs({row , column-1} , visited , grid) ; 
                }
            }
            if (column != visited[0].size()-1) {
                if (!visited[row][column+1] && grid[row][column+1] == '1') {
                    dfs({row , column+1} , visited , grid) ; 
                }
            }            
        }
    int numIslands(vector<vector<char>>& grid) {
    vector<vector<int>> visited(grid.size() ,vector<int>(grid[0].size() , 0 )) ; 
    int count = 0 ;
        for (int i = 0 ; i<grid.size() ; i++) {
            for (int u = 0 ; u<grid[0].size() ; u++) {
                if(!visited[i][u] && grid[i][u] == '1') {
                    dfs({i , u } , visited , grid) ;
                    count++; 
                }

            }
        }
        return count ; 
    }
};
