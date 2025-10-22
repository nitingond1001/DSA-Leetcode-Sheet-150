class Solution {
    struct TrieNode{
        TrieNode* children[26];
        string word;
        TrieNode(){
            word = "";
            for (int i = 0; i < 26; i++) children[i] = nullptr;
        }
    };
    
    TrieNode* root;
    int m, n;
    vector<string> result;

public:
    Solution(){
        root = new TrieNode();
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();

        for(auto &w : words) insert(w);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                dfs(board, i, j, root);
            }
        }

        return result;
    }

private:
    void insert(const string &word){
        TrieNode* node = root;
        for(char c : word){
            int idx = c - 'a';
            if(!node->children[idx]) node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->word = word;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node){
        char c = board[i][j];
        if(c == '#' || !node->children[c - 'a']) return;
        node = node->children[c - 'a'];
        if(!node->word.empty()){
            result.push_back(node->word);
            node->word.clear(); 
        }

        board[i][j] = '#';
        if(i > 0) dfs(board, i - 1, j, node);
        if(j > 0) dfs(board, i, j - 1, node);
        if(i < m - 1) dfs(board, i + 1, j, node);
        if(j < n - 1) dfs(board, i, j + 1, node);
        board[i][j] = c;
    }
};
