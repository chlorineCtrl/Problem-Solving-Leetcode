#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MOD = 1000000007;
const string pattern = "orbitaxian";

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;
        string S;
        cin >> S;


        vector<vector<long long>> dp(10, vector<long long>(N + 1, 0));
        vector<long long> prefix(10, 0);

        for (int i = 0; i < N; ++i) {
            for (int j = 9; j >= 0; --j) {

                if (S[i] == pattern[j]) {
                    if (j == 0) {
                        dp[j][i + 1] = (dp[j][i + 1] + 1) % MOD;
                    } else {
                        int start = max(0, i - K + 1);
                        long long sum = 0;
                        for (int k = start; k < i; ++k) {
                            sum = (sum + dp[j - 1][k + 1]) % MOD;
                        }
                        dp[j][i + 1] = (dp[j][i + 1] + sum) % MOD;
                    }
                }
            }
        }


        long long result = 0;
        for (int i = 0; i < N; ++i) {
            result = (result + dp[9][i + 1]) % MOD;
        }

        cout << result << endl;
    }

    return 0;
}
