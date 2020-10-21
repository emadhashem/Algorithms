
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
struct edge {
    int from, to, w;
    edge(int from , int to , int w) : from(from) , to(to), w(w) {}

    bool operator < (const edge & e) const {
        return w > e.w;
    }
};
pii get_edge(pii p) {
    return {min(p.first , p.second) , max(p.first , p.second)};
}
vector <edge> adj[1003];
int prv[1003][1003], cnt[1003], dis[1003][1003];
map <pii , int> mp;
void dijk(int src , int des) {
    for(int i = 0; i < 1003; i++) dis[src][i] = 1e9 + 5;
    priority_queue <edge> q;
    q.push({-1 , src , 0});
    dis[src][src] = 0;
    while(!q.empty()) {
        edge cur_e = q.top();
        q.pop();
        if(dis[src][cur_e.to] < cur_e.w) continue; // other paths were better
        prv[src][cur_e.to] = cur_e.from;
        for(edge ch : adj[cur_e.to]) {
            if(dis[src][cur_e.from] + ch.w < dis[src][ch.to]) {
                ch.w = dis[src][ch.to] = dis[src][cur_e.from] + ch.w;
                q.push(ch);
            }
        }
    }
    int st = des;
    vector <int> vc;
    while(st != -1) {
        vc.push_back(st);
        st = prv[src][st];
    }

    st = vc[0];
    for(int i = 1; i < vc.size(); i++) {
        pii p = get_edge({st , vc[i]});
        cnt[mp[p]]++;
        st = vc[i];
    }
}
int main () {
    int t = 1;
    //scanf("%d", &t);
    int n, m, k;
    while(t--) {
        cin >> n >> m >> k;
        for(int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            //u--, v--;
            adj[u].push_back({u , v , w});
            adj[v].push_back({v , u , w});
            mp[get_edge({u , v})] = w;
            mp[{u , u}] = 0;
            mp[{v , v}] = 0;
        }
        for(int i = 0; i < k; i++) {
            int u, v;
            cin >> u >> v;
            pii p = get_edge({u , v});
            dijk(p.first , p.second);
        }
        vector <ll> arr;
        for(int i = 0; i < 10; i++) {
            if(cnt[i]) arr.push_back(cnt[i] * i);

        }
        sort(all(arr));
        ll ans = 0;
        for(int i = 0; i < arr.size() - 1; i++) ans += arr[i];
        cout << ans;

    }

    return 0;
}
