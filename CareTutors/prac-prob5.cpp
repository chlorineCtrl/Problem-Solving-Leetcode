class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        ans[0] = 1;
        //prefix table
        for(int i= 1; i < n ; i++){
            ans[i] = ans[i-1]* nums[i-1];
        }

        //postfix table
        int post  = 1 ;

        for(int i = n-1; i>=0; i--){
            ans[i] = ans[i] * post;
            post = post * nums[i];
        }
        return ans;

    }
};
