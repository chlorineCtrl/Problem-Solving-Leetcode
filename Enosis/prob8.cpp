class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<>());
        auto it = unique(nums.begin(), nums.end());
        nums.erase(it, nums.end());

       if(nums.size() < 3){
        return nums[0];
       }else {
        return nums[2];
       }
    }
};
