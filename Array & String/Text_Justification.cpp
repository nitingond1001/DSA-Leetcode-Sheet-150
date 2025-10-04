class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;
        
        while(i < n){
            int lineLength = words[i].size();
            int j = i + 1;
            
            while(j < n && lineLength + 1 + words[j].size() <= maxWidth){
                lineLength += 1 + words[j].size(); 
                j++;
            }
            
            int wordCount = j - i;
            string line;
            
            if(j == n || wordCount == 1){
                line += words[i];
                for(int k = i + 1; k < j; ++k){
                    line += ' ' + words[k];
                }
                line += string(maxWidth - line.size(), ' ');
            } 
            else{
                int totalSpaces = maxWidth - (lineLength - (wordCount - 1));  
                int spacesPerGap = totalSpaces / (wordCount - 1);
                int extraSpaces = totalSpaces % (wordCount - 1);
                
                for(int k = i; k < j - 1; ++k){
                    line += words[k];
                    line += string(spacesPerGap + (extraSpaces > 0 ? 1 : 0), ' ');
                    if(extraSpaces > 0) extraSpaces--;
                }
                line += words[j - 1]; 
            }
            result.push_back(line);
            i = j;
        }
        return result;
    }
};
