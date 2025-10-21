class Solution {
public:
    unordered_map<string, unordered_map<string, double>> graph;
    
    bool dfs(string curr, string target, unordered_set<string>& visited, double& result, double currVal){
        if(curr == target){
            result = currVal;
            return true;
        }
        visited.insert(curr);
        
        for(auto& neighbor : graph[curr]){
            if(!visited.count(neighbor.first)){
                if(dfs(neighbor.first, target, visited, result, currVal * neighbor.second)){
                    return true;
                }
            }
        }
        return false;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i = 0; i < equations.size(); i++){
            string A = equations[i][0];
            string B = equations[i][1];
            double val = values[i];
            graph[A][B] = val;
            graph[B][A] = 1.0 / val;
        }
        vector<double> ans;
        for(auto& q : queries){
            string start = q[0], end = q[1];
            
            if(!graph.count(start) || !graph.count(end)){
                ans.push_back(-1.0);
                continue;
            }
            if(start == end){
                ans.push_back(1.0);
                continue;
            }
            
            unordered_set<string> visited;
            double result = -1.0;
            if(dfs(start, end, visited, result, 1.0)){
                ans.push_back(result);
            } 
            else{
                ans.push_back(-1.0);
            }
        }
        return ans;
    }
};
