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

//https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();

        string st;

        map<char, int> mp;
        mp['('] = ')';
        mp['{'] = '}';
        mp['['] = ']';
        st.push_back(s[0]);
        for(int i = 1; i < n; i++){
            if(mp[st.back()] == s[i])
            {
                st.pop_back();
            }
            else st.push_back(s[i]);
        }
        return st.size() > 0 ? 0 : 1;
    }
};
//https://leetcode.com/problems/merge-two-sorted-lists/
class Solution {
public:
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (!list1) {
        return list2;
    } else if (!list2) {
        return list1;
    }else if(!list1 && !list2) return NULL;
    

    ListNode* current;
    ListNode* fiNal;

    if (list1->val < list2->val) {
        current = list1;
        list1 = list1->next;
    } else {
        current = list2;
        list2 = list2->next;
    }

    fiNal = current;

    while (list1 && list2) {
        if (list1->val < list2->val) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current->next->next = NULL;
        current = current->next;
    }

    if (list1) {
        current->next = list1;
    } else if (list2) {
        current->next = list2;
    }

    return fiNal;
}
};
