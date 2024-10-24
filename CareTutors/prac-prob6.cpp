class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        int ans = 0;
        for(auto& i:s){
            //if s.count(i-1) this doesnt exist then its the start of sequence
            if(!s.count(i-1)){
                int len = 1;
                while(s.count(i+len)){
                    ++len;
                }
                ans = max(len,ans);
            }
        }
        return ans;
    }
};
