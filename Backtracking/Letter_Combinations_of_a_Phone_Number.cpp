class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.empty()) return result;

        vector<string> mapping = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };

        string current;
        backtrack(digits, 0, mapping, current, result);
        return result;
    }

private:
    void backtrack(const string &digits, int index, const vector<string> &mapping,
                   string &current, vector<string> &result){
        if(index == digits.size()){
            result.push_back(current);
            return;
        }

        int digit = digits[index] - '0';
        const string &letters = mapping[digit];
        for(char c : letters){
            current.push_back(c);
            backtrack(digits, index + 1, mapping, current, result);
            current.pop_back(); 
        }
    }
};
