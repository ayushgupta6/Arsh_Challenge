//link: https://leetcode.com/problems/throne-inheritance/description/
class ThroneInheritance {
public:
    unordered_map<string, vector<string>> adj;
    unordered_set<string> dead;
    string king;
    ThroneInheritance(string kingName) {
        king = kingName;
    }
    
    void birth(string parentName, string childName) {
        adj[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead.insert(name);
    }
    
    void solve(string &f, vector<string> &ans){
        if(dead.find(f)==dead.end())
            ans.push_back(f);
        for(auto &i:adj[f])
            solve(i, ans);    
    }
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        solve(king, ans);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
