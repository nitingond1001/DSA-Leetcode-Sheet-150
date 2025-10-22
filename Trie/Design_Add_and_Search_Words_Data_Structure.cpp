class WordDictionary{
    struct TrieNode{
        TrieNode* children[26];
        bool isEnd;
        TrieNode(){
            isEnd = false;
            for(int i = 0; i < 26; i++) children[i] = nullptr;
        }
    };
    
    TrieNode* root;
    
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word){
        TrieNode* node = root;
        for(char c : word){
            int idx = c - 'a';
            if(!node->children[idx]){
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }
    
    bool search(string word){
        return dfsSearch(word, 0, root);
    }
    
private:
    bool dfsSearch(const string& word, int i, TrieNode* node) {
        if(!node) return false;
        if(i == word.size()) return node->isEnd;
        
        char c = word[i];
        if(c == '.'){
            for(int k = 0; k < 26; k++){
                if(node->children[k] && dfsSearch(word, i + 1, node->children[k])){
                    return true;
                }
            }
            return false;
        } 
        else{
            int idx = c - 'a';
            return dfsSearch(word, i + 1, node->children[idx]);
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */