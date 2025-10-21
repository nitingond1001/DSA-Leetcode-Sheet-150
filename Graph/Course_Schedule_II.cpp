class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> order;
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for(auto p : prerequisites){
            int u = p[1];
            int v = p[0];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            order.push_back(node);

            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        if(order.size() == numCourses) return order;
        return {};
    }
};