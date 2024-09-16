class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        vector<int> ans(temperatures.size());
        stack<pair<int,int>> stacked;
        for(int i = 0;  i < temperatures.size() ; i++){
            int currD = i;
            int currT = temperatures[i];
            while(!stacked.empty() && stacked.top().second  < currT){
                int prevD = stacked.top().first;
                int prevT = stacked.top().second;
                stacked.pop();

                ans[prevD] = currD-prevD;

            }

            stacked.push({currD, currT});
        }


return ans;

    }
};
