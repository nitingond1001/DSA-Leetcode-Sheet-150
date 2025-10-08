class Solution {
public:
    int next(int n){
        int sum = 0;
        while(n > 0){
            int lastDigit = n % 10;
            sum += lastDigit * lastDigit;
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> seen;

        while(n != 1 && seen.find(n) == seen.end()){
            seen.insert(n);
            n = next(n);
        }
        return n == 1;
    }
};