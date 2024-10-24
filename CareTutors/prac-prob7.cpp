class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
            sort(strs.begin(),strs.end());
            string f_strs = strs[0];
            string l_strs= strs[strs.size()-1];
            for(int i=0;i < f_strs.size(); i++){
                if(f_strs[i] == l_strs[i]){
                    ans += f_strs[i];
                }
                else break;
            }
            return ans;



    }
};
