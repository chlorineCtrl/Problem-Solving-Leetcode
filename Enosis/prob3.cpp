
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int remainder = k % nums.size();

        reverse(begin(nums), end(nums));
        reverse(begin(nums), begin(nums) + remainder);
        reverse(begin(nums) + remainder, end(nums));


    }
};
