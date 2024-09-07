#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Function to solve the problem for each test case
void solve(int N, int K, const string &S) {
    // Use a boolean array to track if we have seen a binary string of length K
    vector<bool> seen(1 << K, false); // Size 2^K

    // Variable to hold the current window of length K as an integer
    int current = 0;

    // Process the first K-1 characters to set up the window
    for (int i = 0; i < K - 1; ++i) {
        current = (current << 1) | (S[i] - '0');
    }

    // Now, process the string while sliding the window of size K
    for (int i = K - 1; i < N; ++i) {
        current = ((current << 1) | (S[i] - '0')) & ((1 << K) - 1); // Keep only last K bits
        seen[current] = true;
    }

    // Find the lexicographically smallest binary string of length K that is not seen
    for (int i = 0; i < (1 << K); ++i) {
        if (!seen[i]) {
            // Print the binary representation of `i` of length K
            for (int j = K - 1; j >= 0; --j) {
                cout << ((i >> j) & 1);
            }
            cout << endl;
            return;
        }
    }

    // If all possible binary strings of length K are present, print -1
    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        string S;
        cin >> N >> K >> S;
        solve(N, K, S);
    }

    return 0;
}
