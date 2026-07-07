class Solution {
public:
    void checker(vector<char>& arr , int & x) {
        vector<int> freq(10,0) ;  
            for (auto u: arr) {
                if(u != '.' && freq[u-'0']) {
                      x = -1 ;
                }
                if (u!= '.')freq[u- '0'] ++ ; 
            }

            return ;
        
    }

    bool isValidSudoku(vector<vector<char>>& board) {
         int x = 0 ; 
         for (int i = 0 ; i<9 ; i++) {
            checker(board[i] , x) ;
            if (x == -1) return false ;            
         }
         for (int i = 0 ; i<9 ; i++) {
            vector<char> arr(9) ; 
            for (int u =0 ; u<9; u++) {
                arr[u] = board[u][i]  ; 
            }
            checker(arr , x) ; 
            if (x == -1) return false ; 
         }

         for (int i = 0 ; i <=6 ; i += 3) {
            for (int u = 0 ; u<= 6 ; u +=3) {
                vector<char> arr;
                for (int p = i ; p < i +3 ; p++) {
                    for (int q = u ; q < u +3 ; q++) {
                        arr.push_back(board[p][q]);
                    }
                }
                checker(arr,x) ; 
                if(x== - 1) return false ;

            }
         }
         return true ; 

        
    }
};
