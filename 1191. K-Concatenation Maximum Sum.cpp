
#include <bits/stdc++.h>

using namespace std;
const int mx_n = 1e6 + 9;
const int mod = 1e9 + 7;
int get_ans(vector <int> arr , int n, int k) {
    int sum = 0, sum_so_far = 0, ans_i = 0, ans_j = 0, i = 0, j = 0;

    while(j < n) {
        sum += arr[j];
        if(sum )
        if(sum > sum_so_far) {
            sum_so_far = sum;
            ans_i = i;
            ans_j = j;
            ++j;
            continue;
        }
        if(sum < 0) {
            ++j;
            i = j;
            sum = 0;
            continue;
        }
        ++j;
    }
    //puts("");
    //cout << ans_i << " " << ans_j << " " << sum_so_far << "\n";
    if(ans_i == 0 && ans_j == n - 1) {
        long long ans = (sum_so_far * k) % mod;
        return ans;
    }
    if(ans_i > 0 && ans_j < n - 1) return sum_so_far % mod;
    int sum_l = 0, sum_r = 0;
    int x = 0;
    while(x < n) {
        if(sum_l + arr[x] < 0) break;
        sum_l += arr[x++];
    }
    x = n- 1;
    while(x >= 0) {
        if(sum_r + arr[x] < 0) break;
        sum_r += arr[x--];
    }
    return (sum_l + sum_r) % mod;
}
int main() {
    int n, k;
    cin >> n >> k;
    vector <int> arr;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    cout << get_ans(arr , n, k);
}
