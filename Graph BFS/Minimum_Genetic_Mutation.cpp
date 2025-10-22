class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> dict(bank.begin(), bank.end());
        if(!dict.count(endGene)) return -1;

        queue<pair<string,int>> q;
        q.push({startGene, 0});
        unordered_set<string> visited;
        visited.insert(startGene);

        vector<char> choices = {'A','C','G','T'};

        while(!q.empty()){
            auto [gene, steps] = q.front(); q.pop();

            if(gene == endGene) return steps;

            for(int i = 0; i < 8; i++){
                char old = gene[i];
                for(char c : choices){
                    if(c == old) continue;
                    gene[i] = c;
                    if(dict.count(gene) && !visited.count(gene)){
                        visited.insert(gene);
                        q.push({gene, steps + 1});
                    }
                }
                gene[i] = old;
            }
        }
        return -1;
    }
};
