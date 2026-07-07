class Solution {
public:
    int rows ; 
    int columns ;
    vector<pair<int,int>> directions = {{1,0} , {-1,0} , {0,1} , {0,-1}} ;
    void dfs(int row ,int column , vector<vector<int>>& visited , vector<vector<char>>& board)  {
        if (visited[row][column]) return ; 
        visited[row][column] = 1 ; 
        for(auto [r , c] : directions) {
             if(row+r >= 0 && row+r < rows && column+c >=0 && column+c < columns && board[row+r][column+c] == 'O' ){
                dfs(row+r , column + c , visited , board ) ; 
             }
        }

        
    }
    void solve(vector<vector<char>>& board) {
        rows = board.size() ; 
        columns = board[0].size() ; 

        vector<vector<int>> visited(rows , vector<int>(columns , 0)) ; 
        for (int i = 0 ; i<rows ; i++) {
            if(board[i][0] == 'O') {
               dfs(i , 0 , visited , board) ; 
            }
            if(board[i][columns-1] == 'O') {
                dfs(i, columns-1 ,  visited , board) ; 
            }

        }
        for (int i = 0 ; i<columns ; i++) {
            if(board[0][i] == 'O') {
               dfs(0 , i , visited , board) ; 
            }
            if(board[rows-1][i] == 'O') {
                dfs(rows-1, i ,  visited , board) ; 
            }

        }
        for (int i = 0 ; i<rows ; i++) {
           for (int u = 0 ; u<columns ; u++) {
            if (visited[i][u] == 0 ) {
                board[i][u] = 'X' ; 
            }
           }
        }


    }
};
