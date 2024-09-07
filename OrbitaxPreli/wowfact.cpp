#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

vector<long long> countWowSubsequences(const string& s) {
    int n = s.size();
    vector<long long> dp(n + 1, 0);

    long long countW = 0, countWo = 0, countWow = 0;

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'w') {
            countWow += countWo;
            countW++;
        } else if (s[i] == 'o') {
            countWo += countW;
        }
        dp[i + 1] = countWow;
    }

    return dp;
}

pair<int, int> findLongestSubstringWithXWow(const string& s, long long x) {
    int n = s.size();
    vector<long long> dp = countWowSubsequences(s);

    int start = 0;
    long long maxLen = 0;
    pair<int, int> result = {-1, -1};

    for (int i = 0; i < n; ++i) {
        while (start <= i && dp[i + 1] - dp[start] > x) {
            ++start;
        }
        if (dp[i + 1] - dp[start] == x) {
            if (i - start + 1 > maxLen) {
                maxLen = i - start + 1;
                result = {start + 1, i + 1};
            }
        }
    }

    return result;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        long long x;
        cin >> s >> x;

        auto result = findLongestSubstringWithXWow(s, x);
        if (result.first == -1) {
            cout << "-1" << endl;
        } else {
            cout << result.first << " " << result.second << endl;
        }
    }

    return 0;
}
