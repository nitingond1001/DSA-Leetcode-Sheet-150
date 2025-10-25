/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid){
        int n = grid.size();
        return build(grid, 0, 0, n);
    }

    Node* build(vector<vector<int>>& grid, int r0, int c0, int size){
        bool allSame = true;
        int firstVal = grid[r0][c0];
        for(int i = r0; i < r0 + size; i++){
            for(int j = c0; j < c0 + size; j++){
                if(grid[i][j] != firstVal){
                    allSame = false;
                    break;
                }
            }
            if(!allSame) break;
        }

        if(allSame){
            return new Node(firstVal == 1, true);
        }

        int half = size / 2;
        Node* topLeft = build(grid, r0, c0, half);
        Node* topRight = build(grid, r0, c0 + half, half);
        Node* bottomLeft = build(grid, r0 + half, c0, half);
        Node* bottomRight = build(grid, r0 + half, c0 + half, half);

        return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
    }
};