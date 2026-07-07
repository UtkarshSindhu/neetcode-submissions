class Solution {
public:
    int rows ; 
    int columns ; 

    vector<pair<int,int>> directions = {{1,0} , {-1,0} , {0,1} , {0,-1}} ; 
        void  dfs(int row , int column , vector<vector<pair<int,int>>> &grid ,vector<vector<int>>& heights, int x ,int val  ) {
            if (row < 0 || row >= rows || column <0 || column>= columns) return ; 
            if (heights[row][column] < val)  return ; 
            if (x==1) {
                if(grid[row][column].first == 1) return ;        
                grid[row][column].first = 1 ;
            }
            if (x == 2) {
                if(grid[row][column].second == 1) return ;
                grid[row][column].second = 1 ; 
            }    
              for (auto u : directions) {
                    auto [r , c] = u ;
                  
                dfs(row+r , column +c , grid , heights , x ,heights[row][column] );
                    
                }
          }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size() ; 
        columns = heights[0].size() ; 
        vector<vector<pair<int,int>>> grid(rows ,vector<pair<int,int>>(columns , {0,0}) ) ; 
        for (int i = 0 ; i<rows ; i++) {
            dfs ( i , 0 , grid , heights , 1 , 0 )  ; 
        }
        for (int i = 0 ; i<columns ; i++) {
            dfs ( 0 , i , grid , heights , 1 , 0) ; 
        }
        for (int i = 0 ; i<rows ; i++) {
            dfs ( i , columns-1 , grid , heights , 2 , 0 )  ; 
        }
        for (int i = 0 ; i<columns ; i++) {
            dfs ( rows -1 , i , grid , heights , 2 , 0 ) ; 
        }
        vector<vector<int>> answer ;

        for (int i = 0 ; i<rows ; i ++) {
            for (int u = 0; u<columns ; u++) {
                if(grid[i][u].first == 1 && grid[i][u].second == 1) {
                    answer.push_back({i , u}) ; 
                }
            }
        }
        return answer ; 

    }
};
