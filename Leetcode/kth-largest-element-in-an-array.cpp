class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int ans;
        priority_queue<int> pq;

        for(auto x : nums){
            pq.push(x);
        }
        while(k--){
            ans = pq.top();
            pq.pop();
        }
        return ans;
    }
};
