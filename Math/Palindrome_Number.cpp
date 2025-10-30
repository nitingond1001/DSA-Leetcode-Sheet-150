class Solution {
  public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        int rev = 0;
        int dup = x;

        while (x != 0){
            int ld = x % 10;
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && ld > 7)) 
            return false;

            rev = (rev * 10) + ld;
            x = x / 10;
        }
        return dup == rev;
    }
};
