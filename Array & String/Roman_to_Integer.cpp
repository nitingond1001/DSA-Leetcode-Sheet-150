class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman;
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;

        int total = 0;
        int n = s.size();
        
        for(int i = 0; i < n; i++){
            int val = roman[s[i]];

            if(i+1 < n && roman[s[i]] < roman[s[i+1]]){
                total -= val;
            }
            else{
                total += val;
            }
        }
        return total;
    }
};