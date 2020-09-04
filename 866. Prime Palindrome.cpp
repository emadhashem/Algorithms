
#include <bits/stdc++.h>

using namespace std;
const int mx_n = 1e6 + 9;
vector <int> vc;

int create_pali_odd(string cur) {
    string tmp = "";
    int j = 0;
    for(int i = 0; i < cur.size(); i++) if(cur[i] != '0') {
        j = i;
        break;
    }
    for(int i = j; i < cur.size(); i++) tmp += cur[i];
    int ret = 0;
    //cout << tmp;
    for(int i = 0; i < tmp.size(); i++) ret = (ret * 10) + (tmp[i] - '0');
    for(int i = tmp.size() - 2; i >= 0; i--) ret = (ret * 10) + (tmp[i] - '0');
    return ret;
}
bool is_prime(int cur) {
    if(cur <= 1) return 0;
    for(int i = 2; i * i <= cur; i++) if(cur % i == 0) return 0;
    return 1;
}
int fast_power(int a , int b) {
    if(b == 0) return 1;
    if(b == 1) return a;
    if(b % 2 == 0) return fast_power(a , b / 2) * fast_power(a , b / 2);
    return fast_power(a , b / 2) * fast_power(a , b / 2) * a;
}
string get_str(int n) {
    string tmp = "" , ret = "";
    int x = n;
    while(x) {
        tmp += (x % 10) + '0';
        x /= 10;
    }
    for(int i = tmp.size() - 1; i >= 0; i--) ret += tmp[i];
    return ret;
}
int get_ans(int n) {
    // for length of first half of number
    for(int i = 1; i <= 5; i++) {
        for(int j = fast_power(10 , i - 1); j < fast_power(10 , i); j++) {
            int cur = create_pali_odd(get_str(j));
            if(cur >= n && is_prime(cur)) {
                return cur;
            }
        }
    }

}
int main() {

    int n;
    cin >> n;
    cout << get_ans(n);
    return 0;
}
