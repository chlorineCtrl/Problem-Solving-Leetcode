class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        int i = 0;
        int j = 0;
        int counter = t.size();

        for (int i = 0; i < t.size(); i++) {
            mp[t[i]]++;
        }
        int minL = 0;
        int minLength = INT_MAX;

        while (j < s.size()) {
            if (mp[s[j]] > 0) {
                counter--;
            }
            mp[s[j]]--;
            j++;
            while (counter == 0) {
                if (j - i < minLength) {
                    minL = i;
                    minLength = j - i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0) counter++;
                i++;
            }

        }
            if(minLength != INT_MAX){
        return  s.substr(minL, minLength);
    }

    return "";
    }


};
