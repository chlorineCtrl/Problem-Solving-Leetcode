
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
      int zero=0, one=0, diff = 0;
      int length = 0;
        mp[0] = -1;

      for(int i = 0; i < nums.size(); i++){
            nums[i] == 0 ?  zero++ : one++;
            diff = zero - one;

            if(mp.count(diff)){
                length = max(length, i - mp[diff]);
            }
            else mp[diff] = i;
      }
        return length;
    }
};


// ref : https://www.youtube.com/watch?v=agB1LyObUNE&t=696s
