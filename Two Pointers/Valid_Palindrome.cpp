class Solution {
public:
    bool isPalindrome(string& s, int i, int j) {
        while(i < j && !isalnum(s[i])) i++;
        while(i < j && !isalnum(s[j])) j--;

        if(i >= j) return true;

        if(tolower(s[i]) != tolower(s[j]))
            return false;
        return isPalindrome(s, i + 1, j - 1);
    }
    bool isPalindrome(string s){
        int n = s.size();
        return isPalindrome(s, 0, n - 1);
    }
};
