#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MODULO = 1e9 + 7;
const string TARGET = "orbitaxian";

int countValidSubsequences(int length, int maxGap, const string& input)
{
    int patternLength = TARGET.size();


    vector<vector<long long>> dp(patternLength, vector<long long>(length, 0));


    for (int idx = 0; idx < length; ++idx)
    {
        if (input[idx] == TARGET[0])
        {
            dp[0][idx] = 1;
        }
    }


    for (int pIdx = 1; pIdx < patternLength; ++pIdx)
    {
        long long cumulativeSum = 0;
        int rangeStart = 0;

        for (int idx = 0; idx < length; ++idx)
        {

            if (idx - maxGap - 1 >= 0)
            {
                cumulativeSum = (cumulativeSum - dp[pIdx - 1][idx - maxGap - 1] + MODULO) % MODULO;
            }


            if (input[idx] == TARGET[pIdx])
            {
                dp[pIdx][idx] = cumulativeSum;
            }


            cumulativeSum = (cumulativeSum + dp[pIdx - 1][idx]) % MODULO;
        }
    }


    long long total = 0;
    for (int idx = 0; idx < length; ++idx)
    {
        total = (total + dp[patternLength - 1][idx]) % MODULO;
    }

    return total;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numTests;
    cin >> numTests;

    while (numTests--)
    {
        int length, maxGap;
        string input;
        cin >> length >> maxGap;
        cin >> input;

        cout << countValidSubsequences(length, maxGap, input) << endl;
    }

    return 0;
}
