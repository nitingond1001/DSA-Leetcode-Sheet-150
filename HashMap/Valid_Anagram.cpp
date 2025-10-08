class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        int map[26] = {0};
        for(int i = 0; i < s.length(); i++){
            map[s[i] - 'a']++;
            map[t[i] - 'a']--;
        }
        for(int c : map){
            if(c != 0){
                return false;
            }
        }
        return true;
    }
};