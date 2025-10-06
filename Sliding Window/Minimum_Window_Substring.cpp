class Solution {
public:
    string minWindow(string s, string t) {
        if(s == t) return s;
        if(s.length() < t.length()) return "";
        
        int n = s.length(), m = t.length();
        string ans = "";
        int i = 0, j = 0;
        int start = 0, end = 0;
        
        vector<int> freq(128, 0), Window_freq(128, 0);
        for(int k = 0; k < m; k++) freq[t[k]]++;
        
        while(j < n){
            Window_freq[s[j]]++;          
            bool check = true;
            for(int x = 0; x < 128; x++){
                if(freq[x] > 0 && Window_freq[x] < freq[x]){
                    check = false;
                    break;
                }
            }
            
            if(check){
                while(i <= j){
                    if(freq[s[i]] == 0 || Window_freq[s[i]] > freq[s[i]]){
                        Window_freq[s[i]]--;
                        i++;
                    } else break;
                }
                
                if(ans.empty() || (j - i + 1) < ans.size()){
                    ans = s.substr(i, j - i + 1);
                }
            }
            j++;
        }
        return ans;
    }
};