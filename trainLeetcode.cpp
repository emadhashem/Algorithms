
#include <bits/stdc++.h>

using namespace std;
const int mx_n = 1e6 + 9;

int dp[15][15];
string s, t;
string ans = "";
int solve(int i, int j) {
    if(i >= s.size() || j >= t.size()) return 0;

    int &ret = dp[i][j];
    if(ret != -1) return ret;

    if(s[i] == t[j]) {
        ans += s[i];
        return ret = solve(i + 1, j + 1) + 1;
    }
    ret = max(solve(i + 1, j) , solve(i , j + 1));

    return ret;


}
int main() {

    int n;
    cin >> s >> t;

    memset(dp , -1 , sizeof dp);

    cout << solve(0 , 0) << "\n";
    for(int i = 0; i < s.size(); i++) {
        for(int j = 0; j < t.size(); j++) {
            cout << i << " " << j << " " << dp[i][j] << "\n";
        }
    }


    return 0;
}
