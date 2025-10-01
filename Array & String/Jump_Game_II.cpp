class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jump = 0;
        int maxJumps = 0;
        int end = 0;

        for(int i = 0; i < n-1; i++){
            jump = max(jump, (i+nums[i]));

            if(i == end){
                maxJumps++;
                end = jump;
            }
        }
        return maxJumps;
    }
};