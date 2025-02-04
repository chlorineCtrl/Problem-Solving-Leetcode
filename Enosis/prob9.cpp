class Solution {
public:
    int maxArea(vector<int>& height) {
       int l = 0;
       int r = height.size() - 1;
       int area;
       int maxArea = -1;


        for(int  i = 0; i < height.size(); i++){
            area = (r-l) * min(height[l], height[r]);
            maxArea = max(maxArea,area);

            if(height[l] <= height[r]){
                l++;
            }else r--;

        }
        return maxArea;
    }
};
