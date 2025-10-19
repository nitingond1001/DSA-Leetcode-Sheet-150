class Solution {
public:
void dfs(vector<vector<char>>& board, int r, int c, int row, int col){
    if(r < 0 || r >= row || c < 0 || c >= col || board[r][c] != 'O') return;

    board[r][c] = 'T';

    dfs(board, r-1, c, row, col);
    dfs(board, r+1, c, row, col);
    dfs(board, r, c-1, row, col);
    dfs(board, r, c+1, row, col);
}
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();

        for(int r = 0; r < row; r++){
            if(board[r][0] == 'O') dfs(board, r, 0, row, col);
            if(board[r][col-1] == 'O') dfs(board, r, col-1, row, col);
        }

        for(int c = 0; c < col; c++){
            if(board[0][c] == 'O') dfs(board, 0, c, row, col);
            if(board[row-1][c] == 'O') dfs(board, row-1, c, row, col);
        }

        for(int i = 0 ; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'T') board[i][j] = 'O';
            }
        }
    }
};