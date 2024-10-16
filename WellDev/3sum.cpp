
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> s;
        vector<vector<int>> ans;
        int target  = 0;
        for(int i =0 ; i <nums.size(); i++){
            int left = i+1;
            int right = nums.size() -1;
            while(left < right){
                int sum = nums[i]+nums[left] + nums[right];
                if(sum==0){
                    s.insert({nums[i], nums[left] ,nums[right]});
                    left++;
                    right--;
                }
                else if(sum < 0){
                    left++;
                }
                else right--;
            }
        }

        for(auto i:s){
            ans.push_back(i);
        }

        return ans;
    }
};
