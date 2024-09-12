class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;

        int i = 0;
        int j = 0;
        int len = 0;
        while( j < s.size()){
            if(set.find(s[j]) == set.end()){
                set.insert(s[j]);
                len = max(len , j - i + 1);
                j++;
            } else {
                set.erase(s[i]);
                i++;
            }
        }
        return len;
    }
};
