class Solution {
public:
    int totalNQueens(int n) {
        vector<bool> cols(n, false);       
        vector<bool> diag1(2 * n, false); 
        vector<bool> diag2(2 * n, false);  

        return backtrack(0, n, cols, diag1, diag2);
    }

private:
    int backtrack(int row, int n, 
                  vector<bool>& cols, 
                  vector<bool>& diag1, 
                  vector<bool>& diag2){
        if(row == n) return 1; 

        int count = 0;
        for(int col = 0; col < n; col++){
            if(cols[col] || diag1[row - col + n] || diag2[row + col]){
                continue;
            }
            cols[col] = diag1[row - col + n] = diag2[row + col] = true;

            count += backtrack(row + 1, n, cols, diag1, diag2);

            cols[col] = diag1[row - col + n] = diag2[row + col] = false;
        }
        return count;
    }
};
