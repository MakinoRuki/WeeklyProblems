#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 105
using namespace std;
typedef long long ll;
int t, m;
int r1[N], r2[N];
ll g[N], g2[N];
bool check(int cur, ll x) {
    if (g2[cur] < 0) return false;
    g2[cur] -= x;
    if (g2[cur] >= 0) return true;
    bool ok = true;
    ok &= check(r1[cur], -g2[cur]);
    ok &= check(r2[cur], -g2[cur]);
    if (ok) {
        g2[cur] = 0;
    }
    return ok;
}
int main() {
    cin>>t;
    for (int cas = 1; cas <= t; ++cas) {
        cin>>m;
        ll tot = 0LL;
        for (int i = 1; i <= m; ++i) {
            cin>>r1[i]>>r2[i];
        }
        for (int i = 1; i <= m; ++i) {
            cin>>g[i];
            tot += g[i];
        }
        ll l = 0, r = tot;
        while(l < r) {
            ll mid = (l + r + 1LL) / 2LL;
            for (int i = 1; i <= m; ++i) {
                g2[i] = g[i];
            }
            if (check(1, mid)) l = mid;
            else r = mid - 1;
        }
        cout<<"Case #"<<cas<<": "<<r<<endl;
    }
    return 0;
}
