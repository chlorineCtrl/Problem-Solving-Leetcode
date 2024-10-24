class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mapx;
        for(auto i : strs){
            string temp = i;
            sort(i.begin(), i.end());
            mapx[i].push_back(temp);
        }
        for(auto& j: mapx){
            ans.push_back(j.second);
        }
        return ans;

    }
};
