class Solution {
public:
    vector<pair<int,int>> directions = {{0,1} , {0,-1} , {1,0} , {-1,0}} ; 
    void bfs(int row ,int column ,int distance ,vector<vector<int>>& grid ) {
        if(row > grid.size() - 1 || row< 0 || column>grid[0].size()-1 ||column<0 ) return ;  
        if (grid[row][column]==-1) return ;       
        if(distance > grid[row][column]) return ;
        grid[row][column] =  distance ;  
        deque<pair<int,int>> q ; 
        for (auto u : directions) {
            q.push_back({row+u.first , column+u.second}) ; 
        }
        for(auto &u : q) {
            auto [row, column] = u ; 
            q.pop_front();
            bfs(row , column , distance+1 , grid) ; 
        }

    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        for (int i = 0  ; i<grid.size() ; i++) {
            for(int u = 0 ; u <grid[0].size() ; u++) {
                if (grid[i][u] == 0) {
                    for(auto x : directions) {
                        bfs(i+ x.first , u + x.second , 1 , grid);
                    }
                }
            }
        }
    }
};
