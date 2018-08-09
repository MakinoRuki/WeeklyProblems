#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 60
#define pii pair<int, int>
#define mp make_pair
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
int t, n;
ll dp[2][N][N][N][N];
int s, e;
vector<pii> xy;
vector<int> ys;
void update(ll& val, ll add) {
	val = (val + add) % mod;
} 
int main() {
	freopen("replay_value.txt", "r", stdin);
	freopen("cout.txt", "w", stdout);
	cin>>t;
	for (int cas = 1; cas <= t; ++cas) {
		cin>>n>>s>>e;
		xy.clear();
		ys.clear();
		ll tot = 1LL;
		for (int i = 0; i < n; ++i) {
			int x, y;
			cin>>x>>y;
			xy.push_back(mp(x, y));
			ys.push_back(y);
			tot = tot * 4LL % mod;
		}
		ys.push_back(s);
		ys.push_back(e);
		sort(ys.begin(), ys.end());
		sort(xy.begin(), xy.end());
		s = lower_bound(ys.begin(), ys.end(), s) - ys.begin();
		e = lower_bound(ys.begin(), ys.end(), e) - ys.begin();
		memset(dp, 0, sizeof(dp));
		n += 2;
		dp[0][s][s][n - 1][0] = 1;
		for (int i = 0; i < n - 2; ++i) {
			int y = lower_bound(ys.begin(), ys.end(), xy[i].second) - ys.begin();
			int now = !(i & 1);
			memset(dp[now], 0, sizeof(dp[now]));
			for (int sd = s; sd < n; ++sd) {
				for (int su = 0; su <= s; ++su) {
					for (int ed = e; ed < n; ++ed) {
						for (int eu = 0; eu <= e; ++eu) {
							if (!dp[now ^ 1][sd][su][ed][eu]) continue;
							if (!(ed > e && ed < y)) {
								update(dp[now][max(sd, y)][su][ed][eu], dp[now ^ 1][sd][su][ed][eu]);
							}
							if (!(eu < e && y < eu)) {
								update(dp[now][sd][min(su, y)][ed][eu], dp[now ^ 1][sd][su][ed][eu]);
							}
							if (!((y < sd && s < y) || (y < s && su < y))) {
								update(dp[now][sd][su][ed][eu], dp[now ^ 1][sd][su][ed][eu]);
							}
							if (y < e) update(dp[now][sd][su][ed][max(eu, y)], dp[now ^ 1][sd][su][ed][eu]);
							else update(dp[now][sd][su][min(ed, y)][eu], dp[now ^ 1][sd][su][ed][eu]);
						}
					}
				}
			}
		}
		int now = (n - 2) & 1;
		ll ans = 0LL;
		for (int sd = s; sd < n; ++sd) {
			for (int su = 0; su <= s; ++su) {
				for (int ed = e; ed < n; ++ed) {
					for (int eu = 0; eu <= e; ++eu) {
						ans = (ans + dp[now][sd][su][ed][eu]) % mod;
					}
				}
			}
		}
		ans = (tot - ans + mod) % mod;
		cout<<"Case #"<<cas<<": "<<ans<<endl;
	}
	return 0;
}
