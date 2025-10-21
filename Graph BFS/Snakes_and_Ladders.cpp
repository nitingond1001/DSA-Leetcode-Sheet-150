class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();        
        vector<int> arr(n * n + 1, -1); 
        int idx = 1;
        bool leftToRight = true;
        
        for(int r = n - 1; r >= 0; r--){
            if(leftToRight){
                for(int c = 0; c < n; c++){
                    arr[idx++] = board[r][c];
                }
            } 
            else{
                for(int c = n - 1; c >= 0; c--){
                    arr[idx++] = board[r][c];
                }
            }
            leftToRight = !leftToRight;
        }        
        queue<pair<int,int>> q; 
        vector<bool> visited(n * n + 1, false);
        
        q.push({1, 0});
        visited[1] = true;
        
        while(!q.empty()){
            auto [curr, moves] = q.front(); q.pop();
            
            if(curr == n * n) return moves;
            
            for(int dice = 1; dice <= 6; dice++) {
                int next = curr + dice;
                if(next > n * n) break;
                
                if(arr[next] != -1){
                    next = arr[next]; 
                }
                
                if(!visited[next]){
                    visited[next] = true;
                    q.push({next, moves + 1});
                }
            }
        }
        return -1; 
    }
};
