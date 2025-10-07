class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size();
        int col = board[0].size();

        vector<int> dr = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dc = {-1, 0, 1, -1, 1, -1, 0, 1};

        for(int r = 0; r < row; r++){
            for(int c = 0; c < col; c++){
                int live_neighbors = 0;
                for(int n = 0; n < 8; n++){
                    int nr = r + dr[n];
                    int nc = c + dc[n];

                    if(nr >= 0 && nr < row && nc >= 0 && nc < col){
                        if(board[nr][nc] == 1 || board[nr][nc] == 2){
                            live_neighbors++;
                        }
                    }
                }

                if(board[r][c] == 1){
                    if(live_neighbors < 2 || live_neighbors > 3){
                        board[r][c] = 2; 
                    }
                } 
                else if(board[r][c] == 0){
                    if(live_neighbors == 3){
                        board[r][c] = 3; 
                    }
                }
            }
        }

        for(int r = 0; r < row; r++){
            for(int c = 0; c < col; c++){
                if(board[r][c] == 2){
                    board[r][c] = 0;
                } 
                else if(board[r][c] == 3){
                    board[r][c] = 1;
                }
            }
        }
    }
};
