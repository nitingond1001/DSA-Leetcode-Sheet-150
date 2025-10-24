class Solution {
public:
    void backtrack(int idx, vector<vector<int>> &ans, vector<int> &current, vector<int> &candidates, int target){
        if(target == 0){
            ans.push_back(current);
            return;
        }

        for(int i = idx; i < candidates.size(); i++){
            if(candidates[i] > target) break;

            current.push_back(candidates[i]);
            backtrack(i, ans, current, candidates, target-candidates[i]);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> current;
        backtrack(0, ans, current, candidates, target);
        return ans;
    }
};