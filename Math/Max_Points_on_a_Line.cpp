class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 2) return n;
        int result = 0;

        for(int i = 0; i < n; i++){
            map<pair<int,int>, int> slope_count;
            int duplicates = 0;
            int cur_max = 0;

            for(int j = i + 1; j < n; j++){
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if(dx == 0 && dy == 0){
                    duplicates++;
                    continue;
                }

                int g = __gcd(dy, dx);
                if(g != 0){
                    dy /= g;
                    dx /= g;
                }

                if(dx < 0){
                    dx = -dx;
                    dy = -dy;
                }
                slope_count[{dy, dx}]++;
                cur_max = max(cur_max, slope_count[{dy, dx}]);
            }
            result = max(result, cur_max + duplicates + 1); 
        }
        return result;
    }
};