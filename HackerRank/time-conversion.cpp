
#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
        string ans;

        int hourL = (int)s[0] - '0';
        int hourR = (int)s[1] - '0';
        int hour = (hourL * 10) + (hourR);

        int n = hour + 12;

        if(s[8]== 'A'){
            if(hour == 12){
                ans = "00" + s.substr(2,6);
            }
            else ans = s.substr(0,8);
        }

        else if(s[8] == 'P'){
            if(hour == 12){
                ans = "12"+s.substr(2,6);
            }

            else ans = to_string(n) + s.substr(2,6);
        }
        return ans;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
