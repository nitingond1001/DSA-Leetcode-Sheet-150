class Solution {
public:
    int mySqrt(int x) {
        int low = 1;
        int high = x;
        if (x == 0) return 0;

        while(low <= high){
            long long mid = low + (high - low) / 2;
            long long val = (mid * mid);
            if(val <= x){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return high;
    }
};