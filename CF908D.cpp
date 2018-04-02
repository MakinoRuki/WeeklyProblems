#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 1002
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
int k, a, b;
ll dp[N][N];
ll getrev(ll x) {
    ll res = 1LL;
    ll b = mod - 2LL;
    while(b) {
        if (b & 1) res = res * x % mod;
        x = x * x % mod;
        b /= 2;
    }
    return res;
}
int main() {
    cin>>k>>a>>b;
    memset(dp, 0LL, sizeof(dp));
    dp[1][0] = 1LL;
    ll ans = 0LL;
    ll pa = a * getrev(a + b) % mod;
    ll pb = b * getrev(a + b) % mod;
    ll pab = pa * getrev(pb) % mod;
    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j <= k; ++j) {
            if (i + j >= k) {
                ans = (ans + dp[i][j] * ((i + j + pab) % mod) % mod) % mod;
            } else {
                dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * pa % mod) % mod;
                dp[i][j + i] = (dp[i][j + i] + dp[i][j] * pb % mod) % mod;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
