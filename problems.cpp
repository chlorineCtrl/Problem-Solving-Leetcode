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

