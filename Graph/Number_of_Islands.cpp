class Solution {
public:
void dfsRec(vector<vector<char>> &grid, int row, int col){
    if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || 
    grid[row][col] != '1'){
        return;
    }
    grid[row][col] = '0';
    dfsRec(grid, row+1, col);
    dfsRec(grid, row-1, col);
    dfsRec(grid, row, col+1);
    dfsRec(grid, row, col-1);
}
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int row = grid.size();
        int col = grid[0].size();
        int numOfIslands = 0;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '1'){
                    numOfIslands++;
                    dfsRec(grid, i, j);
                }
            }
        }
        return numOfIslands;
    }
};