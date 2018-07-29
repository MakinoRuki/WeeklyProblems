#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 3002
#define inf 1000000000
using namespace std;
typedef long long ll;
const int mod = 1000000007;
int t, n, m;
int a[N], b[N];
int y[N], h[N];
int mh[N];
int dpSafe[N][N], dpZomb[N][N];
int sum[N];
int getpow(int x) {
	int res = 1;
	int pp = mod - 2;
	while(pp) {
		if (pp & 1) {
			res = (int)((ll)res * (ll)x % (ll)mod);
		}
		x = (int)((ll)x * (ll)x % (ll)mod);
		pp /= 2;
	}
	return res;
}
int Prob(int idx, int low, int high) {
	int left = a[idx];
	int right = b[idx];
	left = max(left, low);
	right = min(right, high);
	if (left > right) return 0;
	int an = right - left + 1;
	int bn = b[idx] - a[idx] + 1;
	return (int)((ll)an * (ll)getpow(bn) % (ll)mod);
}
int main() {
	freopen("evening_of_the_living_dead.txt", "r", stdin);
	freopen("dout.txt", "w", stdout);
	cin>>t;
	for (int cas = 1; cas <= t; ++cas) {
		cin>>n>>m;
		for (int i = 1; i < n; ++i) {
			cin>>a[i]>>b[i];
		}
		memset(mh, 0, sizeof(mh));
		for (int i = 1; i <= m; ++i) {
			cin>>y[i]>>h[i];
			mh[y[i]] = max(mh[y[i]], h[i]);
		}
		int hn = 0;
		vector<int> hs;
		hs.clear();
		hs.push_back(0);
		hs.push_back(inf);
		for (int i = 1; i <= n; ++i) {
			if (mh[i] > 0) hs.push_back(mh[i]);
		}
		sort(hs.begin(), hs.end());
		vector<int>::iterator unique_end = unique(hs.begin(), hs.end());
		hs.erase(unique_end, hs.end());
		hn = hs.size();
	//	cout<<"hn="<<hn<<endl;
		// for (int i = 0; i < hn; ++i) {
		// 	cout<<i<<" "<<hs[i]<<endl;
		// }
		for (int i = 1; i <= n; ++i) {
			mh[i] = lower_bound(hs.begin(), hs.end(), mh[i]) - hs.begin();
		}
		memset(dpSafe, 0, sizeof(dpSafe));
		memset(dpZomb, 0, sizeof(dpZomb));
		if (mh[1] > 0) dpZomb[1][mh[1]] = 1;
		else dpSafe[1][0] = 1;
		for (int i = 1; i < n; ++i) {
			int z = mh[i + 1];
			memset(sum, 0, sizeof(sum));
			for (int j = 0; j < hn; ++j) {
				if (dpSafe[i][j]) {
					int d = dpSafe[i][j];
					if (!z || z < j) {
						int p = Prob(i, 0, hs[j]);
						dpSafe[i + 1][j] = (dpSafe[i + 1][j] + (int)((ll)d * (ll)p % (ll)mod)) % mod;
						sum[j + 1] = (sum[j + 1] + d) % mod;
					} else {
						int p = Prob(i, 0, hs[z]);
						dpZomb[i + 1][z] = (dpZomb[i + 1][z] + (int)((ll)d * (ll)p % (ll)mod)) % mod;
						sum[z + 1] = (sum[z + 1] + d) % mod;
						//if (i == 2 && j == 0) cout<<"z="<<z<<" "<<"d="<<d<<endl; 
					}
				}
				if (dpZomb[i][j]) {
					int d = dpZomb[i][j];
					if (z >= j) {
						dpZomb[i + 1][z] = (dpZomb[i + 1][z] + d) % mod;
					} else {
						int p = Prob(i, 0, hs[j]);
						dpZomb[i + 1][j] = (dpZomb[i + 1][j] + (int)((ll)d * (ll)p % (ll)mod)) % mod;
						p = (1 - p + mod) % mod;
						if (z) {
							dpZomb[i + 1][z] = (dpZomb[i + 1][z] + (int)((ll)d * (ll)p % (ll)mod)) % mod;
						} else {
							dpSafe[i + 1][0] = (dpSafe[i + 1][0] + (int)((ll)d * (ll)p % (ll)mod)) % mod;
						}
					}
				}
			}
			int d = 0;
			for (int j = 1; j < hn; ++j) {
				d = (d + sum[j]) % mod;
				int p = Prob(i, hs[j - 1] + 1, hs[j]);
				//if (i + 1 == n && j == 3) cout<<"*"<<" "<<d<<" "<<p<<endl;
				dpSafe[i + 1][j] = (dpSafe[i + 1][j] + (int)((ll)d * (ll)p % (ll)mod)) % mod;
			}
		}
		// for (int i = 1; i <= n; ++i) {
		// 	for (int j = 0; j < hn; ++j) {
		// 		cout<<i<<" "<<j<<" "<<hs[j]<<endl;
		// 		cout<<dpSafe[i][j]<<" "<<dpZomb[i][j]<<endl;
		// 	}
		// }
		int ans = 0;
		for (int i = 0; i < hn; ++i) {
			ans = (ans + dpSafe[n][i]) % mod;
		}
		cout<<"Case #"<<cas<<": "<<ans<<endl;
	}
	return 0;
}
