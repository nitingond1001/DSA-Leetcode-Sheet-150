class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string dir;
        stringstream ss(path);
        
        while(getline(ss, dir, '/')){
            if(dir == "" || dir == "."){
                continue;
            } 
            else if(dir == ".."){
                if(!st.empty()){
                    st.pop_back();
                }
            }
            else{
                st.push_back(dir);
            }
        }
        
        string result = "";
        for(const string& d : st){
            result += "/" + d;
        }
        return result.empty() ? "/" : result;
    }
};
