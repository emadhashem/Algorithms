
#include <bits/stdc++.h>
#define F first
#define S second
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define p_b push_back
#define all(c)              c.begin(), c.end()
using namespace std;
typedef long long ll; //printf("%lld ", ll); to out put long
typedef pair <int , int> pii;
typedef pair <ll , ll> pll;
const double eps = 1e-6;
const int MAXN = 1e5 + 5;
const ll MOD = 1e9 + 7;
bool ODD(ll O) {return (O % 2 != 0);}
ll gcd(ll a, ll b) {return __gcd(a , b);}
ll lcm(ll a, ll b) {return a * b / gcd(a , b);}
int dx[] = {1, 0, -1 ,0 , -1 , 0};
int dy[] = {0, 1, 0, -1 , -1 , 0};
ll power (ll x, ll y) {
    if(y == 0) return 1;
    if(ODD(y)) return (x * power(x , y / 2) * power(x , y / 2));
    return (power(x , y / 2) * power(x , y / 2));
}
/*------ never give up --------*/
vector <int> dfs_num, low_link, in_stack;
vector < vector <int>  > adj, comps;
stack <int> stk;
int cnt_dfs = 0;
void tarjan(int node , int n) {
    low_link[node] = dfs_num[node] = cnt_dfs++;
    in_stack[node] = 1;
    stk.push(node);
    for(int ch : adj[node]) {
        if(dfs_num[ch] == -1) {
            tarjan(ch , n);
            low_link[node] = min(low_link[node] , low_link[ch]);
        } else if(in_stack[ch]) {
            low_link[node] = min(low_link[node] , dfs_num[ch]);
        }
    }
    if(low_link[node] == dfs_num[node]) {
        // to get the nodes in scc
        int x = -1;
        comps.push_back(vector <int> ());
        while(x != node) {
            x = stk.top(), stk.pop(), in_stack[x] = 0;
            comps.back().push_back(x);
        }
    }

}
void scc(int n) {
    dfs_num.resize(n + 1 , -1);
    low_link.resize(n + 1);
    in_stack.resize(n + 1);
    cnt_dfs = 0;
    comps.resize(n + 1);
    for(int i = 0; i < n; i++) {
        if(dfs_num[i] == -1) {
            tarjan(i , n);
        }
    }
    for(int i = 0; i < comps.size(); i++) {
        for(int ch : comps[i]) cout << ch << " ";
        puts("");
    }

}

int main () {
    int t = 1;
    //scanf("%d", &t);
    while(t--) {
        int n, m;
        cin >> n >> m;
        adj.reserve(n + 1);
        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
        }
        scc(n);

    }

    return 0;
}
