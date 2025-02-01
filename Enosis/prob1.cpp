
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         unordered_map<int, int> umap;
        vector<int> ans;

        for(int  i = 0 ; i < nums.size(); i++){
            umap[nums[i]] = i;
        }

        for(int  i = 0; i < nums.size(); i++){
            int remains = target - nums[i];
            if(umap.count(remains) && umap[remains] != i){
                ans.push_back(i);
                ans.push_back(umap[remains]);
                break;
            }
        }
       return ans;

    }
};
