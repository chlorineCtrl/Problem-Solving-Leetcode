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

//https://leetcode.com/problems/search-insert-position/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while(low <= high){
          int mid = (low+high)/2;
            if(nums[mid] == target){
              return mid;
            }
            else if(nums[mid] < target){
              low = mid + 1;
            }
            else if(nums[mid] > target)
            high = mid-1;
        }
        return high+1;

    }
};

//https://leetcode.com/problems/climbing-stairs/
class Solution {
public:
    int climbStairs(int n) {
        if(n<=2)
         return n;
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++)
         dp[i]=dp[i-1]+dp[i-2];
        
        return dp[n];
    }
};

//https://leetcode.com/problems/binary-tree-inorder-traversal/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    if (root == NULL) return ans;
    vector<int> left = inorderTraversal(root->left);
    ans.insert(ans.end(), left.begin(), left.end());
    ans.push_back(root->val);
    vector<int> right = inorderTraversal(root->right);
    ans.insert(ans.end(), right.begin(), right.end());
    return ans;
}

};

//https://leetcode.com/problems/symmetric-tree/

class Solution {
public:
    bool isSymmetric(TreeNode* root) {

        return myLogic(root->left, root->right);
    }

    bool myLogic(TreeNode* leftn, TreeNode* rightn){
        if(leftn == nullptr && rightn == nullptr) return true;
        if(leftn == nullptr || rightn == nullptr || leftn->val != rightn->val) return false;

        return myLogic(leftn->left, rightn->right) &&  myLogic(leftn->right, rightn->left);
    }
};

//https://leetcode.com/problems/maximum-depth-of-binary-tree/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int left = maxDepth(root->left)+1;
        int right = maxDepth(root->right)+1;

        return max(right,left);

    }

   
};

//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buyPrice = INT_MAX; //max possible integer
        int maxProfit = 0;

        for(int i = 0; i < n ; i++){
            buyPrice = min(buyPrice,prices[i]);
            maxProfit = max(maxProfit,prices[i]-buyPrice);
        }
        return maxProfit;

    }
};

//https://leetcode.com/problems/single-number/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i<nums.size(); i++){
            ans = ans ^ nums[i];
        }
        return ans;
    }
};

//https://leetcode.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};

//https://leetcode.com/problems/reverse-linked-list/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

            ListNode* temp2;
            ListNode* temp1 = NULL;


            while(head != NULL){
            temp2 = head->next;
            head->next = temp1;
            temp1 = head;
            head = temp2;
            }
        return temp1;
    }
};

//https://leetcode.com/problems/invert-binary-tree/

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root) {
            std::swap(root->left, root->right);
            invertTree(root->left);
            invertTree(root->right);
        }
        return root;
    }
};

//https://leetcode.com/problems/palindrome-linked-list/

class Solution {
public:
    struct ListNode* copy(struct ListNode* start1)

    {

        if (start1 == NULL)
            return NULL;

        struct ListNode* temp =
            (struct ListNode*)malloc(sizeof(struct ListNode));

        temp->val = start1->val;

        temp->next = copy(start1->next);

        return temp;
    }

    bool areIdentical(struct ListNode* a, struct ListNode* b) {
        while (a != NULL && b != NULL) {
            if (a->val != b->val)
                return false;

            a = a->next;
            b = b->next;
        }

        return (a == NULL && b == NULL);
    }
    bool isPalindrome(ListNode* head) {
        ListNode* pastHead = copy(head);
        ListNode* temp1 = NULL;
        ListNode* temp2;
        while (head) {
            temp2 = head->next;
            head->next = temp1;
            temp1 = head;
            head = temp2;
        }
        if (areIdentical(pastHead, temp1))
            return true;
        else
            return false;
    }
};

//https://leetcode.com/problems/move-zeroes/


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;

        for(int i=0; i < nums.size(); i++){
            if(nums[i] != 0){
                nums[j] = nums[i];
                j++;
            }
        }
        for(j;j<nums.size();j++){
            nums[j] = 0;
        }
        
    }
};

//starts neetcode

//https://leetcode.com/problems/contains-duplicate/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> ans;
        for(int i = 0; i < nums.size(); i++){
            ans.insert(nums[i]);
        }
        if(nums.size() == ans.size()) return false;
        else return true;
    }
};

//https://leetcode.com/problems/valid-anagram/


class Solution {
public:
    bool isAnagram(string s, string t) {
        bool verdict = true;
        unordered_map<char, int> ans;

        for (auto x : s) {
            ans[x]++;
        }
        for (auto x : t) {
            ans[x]--;
        }
        for (auto x : ans) {
            if (x.second != 0) {
                verdict = false;
            }
        }
        return verdict;
    }
};

//https://leetcode.com/problems/group-anagrams/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ans;
        for(auto x:strs){
            string temp = x;
            sort(temp.begin(),temp.end());
            ans[temp].push_back(x);
        }
        vector<vector<string>> final_ans;
        for(auto y:ans){
            final_ans.push_back(y.second);
        }
        return final_ans;
    }
};

//https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        priority_queue<pair<int,int>> pq;
        vector<int> ans;

        for (auto x : nums) {
            freq[x]++;
        }

        for(auto y:freq){
            pq.push({y.second,y.first});
        }

        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

//https://leetcode.com/problems/is-subsequence/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.length();
        int n = t.length();

        return ChodseAmare(s,t,m,n);
    }

    bool ChodseAmare(string s, string t,int m,int n) {

            if(m==0){
                return true;
            }
            else if(n==0){
                return false;
            }

            if(s[m-1] == t[n-1]){
                return ChodseAmare(s,t,m-1,n-1);
            }

            else {
                return ChodseAmare(s,t,m,n-1);
            }
    }
};

//Concatenation of Array

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> v;
      for(int i = 0 ; i < 2; i++){
          for(int j = 0;  j < nums.size(); j++){
              v.push_back(nums[j]);
          }
      } 
      return v; 
    }
};

//Richest Customer Wealth

class Solution {
public:
    int maximumWealth(vector<vector<int>>& v) {
        int sum = 0;
        int smax = 0;

        vector<vector<int>>::iterator it1;
        vector<int>::iterator it2;
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v[i].size(); j++) {
                sum += v[i][j];
            }
            smax = max(smax,sum);
            sum = 0 ;
        }
        return smax;
    }
};

//Count Items Matching a Rule

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int ans = 0;
        for(int i = 0; i < items.size(); i++){
            if(ruleKey=="color" && items[i][1]== ruleValue) ans++;
            else if(ruleKey=="type" && items[i][0]==ruleValue) ans++;
            else if(ruleKey=="name" && items[i][2]==ruleValue) ans++;
            
        }
        return ans;
    }
};

//Find the Middle Index in Array

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int left_sum = 0;
        int right_sum = 0;
        int retur = -4;

        for (int i = 0; i < nums.size(); i++) {
            for (int x = 0; x < i; x++) {
                left_sum += nums[x];
                
            }
            for (int y = i + 1; y < nums.size(); y++) {
                right_sum += nums[y];
                
            }

            if (left_sum == right_sum){
retur = i;
break;
            }
                

            left_sum = 0;
            right_sum = 0;
        }
        if(retur == -4) retur = -1;
        return retur;
    }
};


