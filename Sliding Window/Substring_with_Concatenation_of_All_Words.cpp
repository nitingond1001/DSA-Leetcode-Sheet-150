class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if(words.empty() || s.empty()) 
            return result;

        int word_len = words[0].size();
        int word_count = words.size();
        int concat_len = word_len * word_count;
        int n = s.size();

        unordered_map<string, int> word_freq;
        for(const string& word : words)
            word_freq[word]++;

        for(int i = 0; i < word_len; i++){
            int left = i, count = 0;
            unordered_map<string, int> window_freq;

            for(int j = i; j <= n - word_len; j += word_len){
                string word = s.substr(j, word_len);

                if(word_freq.count(word)){
                    window_freq[word]++;
                    count++;

                    while(window_freq[word] > word_freq[word]){
                        string left_word = s.substr(left, word_len);
                        window_freq[left_word]--;
                        left += word_len;
                        count--;
                    }

                    if(count == word_count){
                        result.push_back(left);
                        string left_word = s.substr(left, word_len);
                        window_freq[left_word]--;
                        left += word_len;
                        count--;
                    }
                } 
                else{
                    window_freq.clear();
                    count = 0;
                    left = j + word_len;
                }
            }
        }
        return result;
    }
};