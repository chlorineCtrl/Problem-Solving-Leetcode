// https://leetcode.com/problems/roman-to-integer/
class Solution {
public:
    int romanToInt(string romanInput) {
        int count = 0;
        unordered_map<char, int> map;

        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;

        for(int i = 0; i< romanInput.size(); i++){
            if(map[romanInput[i]] < map[romanInput[i+1]]){
                count -= map[romanInput[i]];
            }
            else
            {
                count += map[romanInput[i]];
            }
        }
        
        return count;
    }
};
//https://leetcode.com/problems/longest-common-prefix/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string sum = "";
        sort(strs.begin(), strs.end());
        string firstString = strs[0];
        string lastString = strs[strs.size()-1];
        for(int i = 0; i < firstString.size(); i++){
            if(firstString[i] == lastString[i]){
                sum  += firstString[i];
            }
            else break;
        }

        return sum;
    }
};
