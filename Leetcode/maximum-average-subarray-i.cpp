
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maximum = 0;
        double sum = 0;
        for(int i = 0; i <k ; i++){
            sum += nums[i];
        }
            maximum = sum;

            for(int i = k; i < nums.size(); i++){
                sum += nums[i];
                sum -= nums[i-k];

                maximum = max(maximum, sum);

            }
            return maximum/k;
    }

};
