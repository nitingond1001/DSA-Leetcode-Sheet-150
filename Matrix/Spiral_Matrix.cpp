class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        int srow = 0, erow = m-1, scol = 0, ecol = n-1;

        while(srow <= erow && scol <= ecol){

            //top --> left to right
            for(int j = scol; j <= ecol; j++){
                ans.push_back(matrix[srow][j]);
            }

            //right --> top to bottom
            for(int i = srow+1; i <= erow; i++){
                ans.push_back(matrix[i][ecol]);
            }

            //bottom --> right to left
            for(int j = ecol-1; j >= scol; j--){
                if(srow == erow){
                    break;
                }
                ans.push_back(matrix[erow][j]);
            }

            //left --> bottom to top
            for(int i = erow-1; i >= scol+1; i--){
                if(scol == ecol){
                break;
            }
                ans.push_back(matrix[i][scol]);
            }
            srow++; scol++; erow--; ecol--;
        }
        return ans;
    }
};