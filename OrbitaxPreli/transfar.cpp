#include <bits/stdc++.h>
using namespace std;


bool incrementBinaryString(string &binStr) {
    int length = binStr.size();
    for (int i = length - 1; i >= 0; i--) {
        if (binStr[i] == '0') {
            binStr[i] = '1';
            return true;
        } else {
            binStr[i] = '0';
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numTestCases;
    cin >> numTestCases;
    vector<string> results(numTestCases);

    for (int i = 0; i < numTestCases; ++i) {
        int strLength, blockSize;
        cin >> strLength >> blockSize;
        string binaryStr;
        cin >> binaryStr;

        unordered_set<string> blockSet;
        for (int j = 0; j <= strLength - blockSize; ++j) {
            blockSet.insert(binaryStr.substr(j, blockSize));
        }

        string binaryCandidate(blockSize, '0');
        bool found = false;

        do {
            if (blockSet.find(binaryCandidate) == blockSet.end()) {
                results[i] = binaryCandidate;
                found = true;
                break;
            }
        } while (incrementBinaryString(binaryCandidate));

        if (!found) {
            results[i] = "-1";
        }
    }

    for (const string &result : results) {
        cout << result << '\n';
    }

    return 0;
}
