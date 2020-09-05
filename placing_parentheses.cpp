#include <bits/stdc++.h>

using namespace std;
int mx_v[105][105], mn_v[105][105];
int get_val(int a, int b , char op) {
    if(op == '*') return a * b;
    if(op == '+') return a + b;
    return a - b;
}
int get_max_val(string exp) {
    int n = (exp.size() + 1) / 2;
    for(int i = 0; i < n; i++) mx_v[i][i] = exp[2 * i] - '0', mn_v[i][i] = exp[2 * i] - '0';
    // for size of subproblems
    for(int s = 0; s < n - 1; s++) {
        // for start of the subproblems
        for(int i = 0; i < n - s - 1; i++) {
            // for end of the subproblems
            int j = i + s + 1;
            int mini = INT_MAX;
            int maxi = INT_MIN;
            for(int k = i; k < j; k++) {
                // for walking between the ops from i to j
                int a = get_val(mx_v[i][k] , mx_v[k + 1][j] , exp[2 * k + 1]);
                int b = get_val(mx_v[i][k] , mn_v[k + 1][j] , exp[2 * k + 1]);
                int c = get_val(mn_v[i][k] , mx_v[k + 1][j] , exp[2 * k + 1]);
                int d = get_val(mn_v[i][k] , mn_v[k + 1][j] , exp[2 * k + 1]);
                mini = min(mini , min(a , min(b , min(c ,d ))));
                maxi = max(maxi , max(a , max(b , max(c ,d ))));
            }
            mx_v[i][j] = maxi;
            mn_v[i][j] = mini;
        }
    }
    return mx_v[0][n - 1];
}
int main() {
    string exp;
    cin >> exp;
    cout << get_max_val(exp);

    return 0;
}
