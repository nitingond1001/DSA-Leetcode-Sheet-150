class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int charCount[256] = {0};

        for(char ch : magazine){
            charCount[ch]++;
        }

        for(char ch : ransomNote){
            if(charCount[ch] == 0){
                return false;
            }
            charCount[ch]--;
        }
        return true;
    }
};